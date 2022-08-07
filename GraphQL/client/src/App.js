import React, { Fragment } from 'react';
import { useApolloClient, gql, useSubscription } from '@apollo/client'
import { Switch, Route, BrowserRouter } from 'react-router-dom';
import Users from './Users';
import AuthorizedUser from './AuthorizedUser'
import Photo from './Photo';
import PostPhoto from './PostPhoto';
import { LISTEN_FOR_USERS } from './Subscription'

export const ROOT_QUERY = gql`
  query allUsers {
    totalUsers
    totalPhotos
    allUsers { ...userInfo }
    me { ...userInfo }
    allPhotos {
      id
      name
      url
    }
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
    }});
  }
  return (
    <BrowserRouter>
    <Switch>
      <Route exact path="/"
        component={() => (
          <Fragment>
            <AuthorizedUser />
            <Users />
            <Photo />
          </Fragment>
      )}/>
      <Route path="/newPhoto" component={PostPhoto} />
      <Route component={({location}) => <h1>"{location.pathname}" not found</h1>} />
    </Switch>
  </BrowserRouter>
  )
}

export default App;