import { React, useState, useEffect } from 'react';
import { useQuery, useMutation, gql, useApolloClient } from '@apollo/client';
import { ROOT_QUERY } from './App';
import { NavLink } from 'react-router-dom';

const Me = ({ logout, requestCode, signingIn }) => {
  const {loading, error, data} = useQuery(ROOT_QUERY);
  if (error) {
    throw new Error(error);
  }
  if (data?.me) return <CurrentUser {...data.me} logout={logout} />
  if (error) return <p>{`Error! ${error.message}`}</p>
  if (loading) return <p>loading...</p>
  return <button onClick={requestCode} disable={signingIn}>깃허브로 로그인</button>
}

const CurrentUser = ({ name, avatar, logout }) => (
  <div>
    <img src={avatar} width={48} height={48} alt="" />
    <button onClick={logout}>logout</button>
    <NavLink to="/newPhoto">Post Photo</NavLink>
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
    client.writeQuery({ query: ROOT_QUERY, data: {
      totalUsers: data.totalUsers,
      allUsers: data.allUsers,
      me: null,
    }});
  }
  const [githubMutation, {loading, error, data}] = useMutation(GITHUB_AUTH_MUTATION, {
    refetchQueries: [{query: ROOT_QUERY}],
    update: authorizationComplete,
  });

  return <Me signingIn={signingIn} requestCode={requestCode} logout={logout} />  
}

export default AuthorizedUser;