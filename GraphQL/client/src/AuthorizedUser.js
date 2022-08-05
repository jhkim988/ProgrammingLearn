import React, { useState, useEffect } from 'react';
import { useLocation } from 'react-router-dom';
import { Query, Mutation, useApolloClient } from 'react-apollo';
import { gql } from 'apollo-boost';
import { ROOT_QUERY } from './App';

const Me = ({ logout, requestCode, signingIn }) => (
  <Query query={ROOT_QUERY}>
    {
    ({ loading, data }) => data.me ?
      <CurrentUser {...data.me} logout={logout} /> :
      loading ?
        <p>loading...</p> :
        <button onClick={requestCode} disable={signingIn}>깃허브로 로그인</button>  
    }
  </Query>
)

const CurrentUser = ({ name, avatar, logout }) => (
  <div>
    <img src={avatar} width={48} height={48} alt="" />
    <button onClick={logout}>logout</button>
  </div>
)

const GITHUB_AUTH_MUTATION = gql`
  mutation githubAuth($code: String!) {
    githubAuth(code: $code) {
      token
    }
  }
`

const AuthorizedUser = function() {
  const client = useApolloClient();
  const [ signingIn, setSigningIn ] = useState(false);
  const [ location ] = useState(window.location);
  let githubMutation;
  useEffect(() => {
    if (window.location.search.match(/code=/)) {
      setSigningIn(true);
      const code = window.location.search.replace("?code=", "");
      githubMutation({ variables: {code} });
    } 
  }, [location])

  const requestCode = () => {
    var clientID = process.env.REACT_APP_CLIENT_ID;
    window.location = `http://github.com/login/oauth/authorize?client_id=${clientID}&scope=user`;
  }

  const authorizationComplete = (cache, { data }) => {
    localStorage.setItem('token', data.githubAuth.token);
    window.history.pushState({}, null, '/');
    setSigningIn(false);
  }

  const logout = () => {
    localStorage.removeItem('token')
    let data = client.readQuery({ query: ROOT_QUERY });
    data.me = null;
    client.writeQuery({ query: ROOT_QUERY, data});
  }

  return (
    <Mutation mutation={GITHUB_AUTH_MUTATION} update={authorizationComplete} refetchQueries={[{query: ROOT_QUERY}]}>
    {
      mutation => {
        githubMutation = mutation;
        return <Me signingIn={signingIn} requestCode={requestCode} logout={logout} />
      }
    }
  </Mutation>
  )
}

export default AuthorizedUser;