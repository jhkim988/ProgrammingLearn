import React, { useEffect } from 'react';
import { useApolloClient, gql, useSubscription } from '@apollo/client'
import { BrowserRouter } from 'react-router-dom';
import Users from './Users';
import AuthorizedUser from './AuthorizedUser'
import Test from './Test'
import { LISTEN_FOR_USERS } from './Subscription'

export const ROOT_QUERY = gql`
  query allUsers {
    totalUsers
    allUsers { ...userInfo }
    me { ...userInfo }
  } 
  fragment userInfo on User {
    githubLogin
    name
    avatar
  }
`;

const App = () => {
  const client = useApolloClient();
  const {data, loading} = useSubscription(LISTEN_FOR_USERS);
  const cachedata = client.readQuery({ query: ROOT_QUERY });
  if (data) {
    // cachedata is readonly...
    client.writeQuery({ query: ROOT_QUERY, data: {
      totalUsers: cachedata.totalUsers+1,
      allUsers: [...cachedata.allUsers, data.newUser],
      me: cachedata.me,
    } });
  }
  return (
    <BrowserRouter>
    <div>
      <AuthorizedUser />
      <Users />
    </div>  
  </BrowserRouter>
  )
}

export default App;