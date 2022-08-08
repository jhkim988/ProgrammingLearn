import React from 'react';
import { createRoot } from 'react-dom/client';
import App from './App';
import {
  ApolloProvider,
  InMemoryCache,
  ApolloClient,
  HttpLink,
  ApolloLink,
  split,
} from '@apollo/client';
import { createUploadLink } from 'apollo-upload-client';
import { persistCache } from 'apollo-cache-persist';
import { GraphQLWsLink } from '@apollo/client/link/subscriptions';
import { createClient } from 'graphql-ws'
import { getMainDefinition, offsetLimitPagination } from '@apollo/client/utilities';

const container = document.getElementById('root');
const root = createRoot(container);

const cache = new InMemoryCache({
  typePolicies: {
    Query: {
      fields: {
        allPhotos: offsetLimitPagination(),
      }
    }
  }
});
persistCache ({
  cache,
  storage: localStorage
});

if (localStorage['apollo-cache-persist']) {
  let cacheData = JSON.parse(localStorage['apollo-cache-persist']);
  cache.restore(cacheData);
}

const httpLink = new createUploadLink({ uri: 'http://localhost:4000/graphql'});
const wsLink = new GraphQLWsLink(createClient({
  url: `ws://localhost:4000/graphql`,
  options: { reconnect: true }
}));
const authLink = new ApolloLink((operation, forward) => {
  operation.setContext(context => ({
    headers: {
      ...context.headers,
      authorization: localStorage.getItem('token'),
    }
  }));
  return forward(operation);
});
const httpAuthLink = authLink.concat(httpLink);
const link = split(({query}) => {
  const { kind, operation } = getMainDefinition(query);
  return kind === 'OperationDefinition' && operation === 'subscription'
}, wsLink, httpAuthLink);


const client = new ApolloClient({ cache, link });

root.render(
  <ApolloProvider client={client}>
    <App />
  </ApolloProvider>
);