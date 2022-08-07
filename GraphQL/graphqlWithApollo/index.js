const { readFileSync } = require('fs');
const { createServer } = require('http');
const express = require('express');
const { ApolloServer } = require('apollo-server-express');
const {
  ApolloServerPluginDrainHttpServer,
  ApolloServerPluginLandingPageLocalDefault,
} = require('apollo-server-core');
const { PubSub } = require('graphql-subscriptions');
const { WebSocketServer } = require('ws');
const { useServer } = require('graphql-ws/lib/use/ws');
const { makeExecutableSchema } = require('@graphql-tools/schema');
const expressPlayground = require('graphql-playground-middleware-express').default;
require('dotenv').config()

const typeDefs = readFileSync('./typeDefs.graphql', 'utf-8');
const resolvers = require('./resolvers');
const schema = makeExecutableSchema({typeDefs, resolvers});
const { MongoClient, ConnectionClosedEvent } = require('mongodb');

const start = async () => {
  const app = express();
  const httpServer = createServer(app);
  const client = await MongoClient.connect(process.env.DB_HOST, {useNewUrlParser: true});
  const db = client.db('local');
  const pubsub = new PubSub();
  const server = new ApolloServer({
    schema,
    csrfPrevention: true,
    context: async ({ req, connection }) => {
      const githubToken = req ? req.headers.authorization : connection.context.Authorization;
      const currentUser = await db.collection('users').findOne({ githubToken })
      return { db, currentUser, pubsub } // http context(NOT WebSocket)
    },
    cors: {
      origin: ["http://localhost:3000"]
    },
    plugins: [
      ApolloServerPluginDrainHttpServer({httpServer}),
      {
        async serverWillStart() {
          return {
            async drainServer() {
              await serverCleanup.dispose();
            }
          }
        }
      },
      ApolloServerPluginLandingPageLocalDefault({ embed: true }),
    ]
  });
  await server.start();
  server.applyMiddleware({app});
  app.get('/', (req, res) => {
      res.set({"content-type" : "text/html; charset=utf-8"});
      res.end('PhotoShare API에 오신 것을 환영합니다.');
    }
  );
  app.get('/playground', expressPlayground({ endpoint: '/graphql'}));
  // app.listen({ port: 4000 }, () => console.log(`GraphQL Server running @ http://localhost:4000${server.graphqlPath}`));

  const wsServer = new WebSocketServer({
    server: httpServer,
    path: '/graphql'
  });
  const getDynamicContext = async (ctx, msg, args) => {
    const githubToken = ctx.Authorization;
    const currentUser = await db.collection('users').findOne({githubToken});
    return { pubsub, db, currentUser };
  }
  const serverCleanup = useServer({ 
    schema,
    context: async (ctx, msg, args) => {
      return await getDynamicContext(ctx, msg, args);
    }
  }, wsServer);
  httpServer.listen({ port: 4000 }, () => console.log(`GraphQL Server running at localhost:4000${server.graphqlPath}`));
}
start();