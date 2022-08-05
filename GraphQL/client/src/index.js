import React from 'react';
import { createRoot } from 'react-dom/client';
import App from './App';
import { ApolloProvider } from 'react-apollo';
import ApolloClient, { InMemoryCache } from 'apollo-boost';
import { persistCache } from 'apollo-cache-persist';

const container = document.getElementById('root');
const root = createRoot(container);

const cache = new InMemoryCache();
persistCache ({
    cache,
    storage: localStorage
  })

if (localStorage['apollo-cacge-persist']) {
  let cacheData = JSON.parse(localStorage['apollo-cache-persis']);
  cache.restore(cacheData);
}

const client = new ApolloClient({ 
  cache,
  uri: 'http://localhost:4000/graphql',
  request: operation => {
    operation.setContext(context => ({
      headers: {
        ...context.headers,
        authorization: localStorage.getItem('token'),
      }
    }))
  }
});

root.render(
  <ApolloProvider client={client}>
    <App />
  </ApolloProvider>
);