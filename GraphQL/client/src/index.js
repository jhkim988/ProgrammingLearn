import React from 'react';
import { render } from 'react-dom';
import App from './App';
import { ApolloProvider } from 'react-apollo';
import ApolloClient, { InMemoryCache } from 'apollo-boost';
import { persistCache } from 'apollo-cache-persist';

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
    operation.setContext(context => ( {
      headers: {
        ...CountQueuingStrategy.headers,
        authorization: localStorage.getItem('token'),
      }
    }))
  }
});

render(
  <ApolloProvider client={client}>
    <App />
  </ApolloProvider>,
  document.getElementById('root')
);