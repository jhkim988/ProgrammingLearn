import { readFileSync } from 'fs';
import { createServer } from 'http';
import { WebSocketServer } from 'ws';
import path from 'path';
import express from 'express';
import { ApolloServer } from 'apollo-server-express';
import {
  ApolloServerPluginDrainHttpServer,
  ApolloServerPluginLandingPageLocalDefault,
} from 'apollo-server-core';
import { PubSub } from 'graphql-subscriptions';
import { useServer } from 'graphql-ws/lib/use/ws';
import { makeExecutableSchema } from '@graphql-tools/schema';
import expressPlayground from 'graphql-playground-middleware-express';
import dotenv from 'dotenv';
import graphqlUploadExpress from 'graphql-upload/graphqlUploadExpress.mjs';
import resolvers from './resolvers/index.js'
import { MongoClient } from 'mongodb';
import cors from 'cors';
dotenv.config();

const typeDefs = readFileSync('./typeDefs.graphql', 'utf-8');
const schema = makeExecutableSchema({typeDefs, resolvers});

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
  app.use(cors({
    origin: 'http://localhost:3000',
    Credential: true,
  }));
  app.use('/img/photos', express.static(path.join(path.resolve(), 'assets', 'photos')));
  app.use(graphqlUploadExpress());
  app.get('/', (req, res) => {
      res.set({"content-type" : "text/html; charset=utf-8"});
      res.end('PhotoShare API에 오신 것을 환영합니다.');
    }
  );
  app.get('/playground', expressPlayground.default({ endpoint: '/graphql'}));
  // app.listen({ port: 4000 }, () => console.log(`GraphQL Server running @ http://localhost:4000${server.graphqlPath}`));
  server.applyMiddleware({app});
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
  httpServer.timeout = 5000;
  httpServer.listen({ port: 4000 }, () => console.log(`GraphQL Server running at localhost:4000${server.graphqlPath}`));
}
start();