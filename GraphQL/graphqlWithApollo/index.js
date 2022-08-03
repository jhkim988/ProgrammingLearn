const { readFileSync } = require('fs');
const { ApolloServer } = require('apollo-server-express');
const express = require('express');
const expressPlayground = require('graphql-playground-middleware-express').default;
require('dotenv').config()

const typeDefs = readFileSync('./typeDefs.graphql', 'utf-8');
const resolvers = require('./resolvers');
const { MongoClient } = require('mongodb');

const start = async () => {
  const app = express();
  // const dbConnect = require('./models')
  // dbConnect();

  const client = await MongoClient.connect(process.env.DB_HOST, {useNewUrlParser: true});
  const db = client.db('local');
  const context = { db }
  const server = new ApolloServer({ typeDefs, resolvers, context });
  await server.start();
  await server.applyMiddleware({app});
  app.get('/', (req, res) => {
      res.set({"content-type" : "text/html; charset=utf-8"});
      res.end('PhotoShare API에 오신 것을 환영합니다.');
    }
  );
  app.get('/playground', expressPlayground({ endpoint: '/graphql'}));
  app.listen({ port: 4000 }, () => console.log(`GraphQL Server running @ http://localhost:4000${server.graphqlPath}`));
}

start();