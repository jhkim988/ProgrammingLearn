import React, { Component } from 'react';
import { withApollo, withRouter } from 'react-router-dom';
import { Mutation } from 'react-apollo';
import { gql } from 'apollo-boost';
import { ROOT_QUERY } from './App';

const Me = ({ logout, requestCode, signingIn }) => {
  <Query query={ROOT_QUERY}>
    {
    ({ loading, data }) => data.me ?
      <CurrentUser {...data.me} logout={logout} /> :
      loading ?
        <p>loading...</p> :
        <button onClick={requestCode} disable={signingIn}>깃허브로 로그인</button>  
    }
  </Query>
}

const GITHUB_AUTH_MUTATION = gql`
  mutation githubAuth($code: code) {
    githubAuth(code: $code) {
      token
    }
  }
`

class AuthorizedUser extends Component {
  state = { signingIn : false }
  authorizationComplete = (cache, { data }) => {
    localStorage.setItem('token', data.githubAuth.token);
    this.props.history.replace('/');
    this.setState({ signingIn: false });
  }
  compoenentDidMount() {
    if (window.location.search.match(/code=/)) {
      this.setState({ signingIn: true})
      const code = window.location.search.replace("?code=", "");
      this.githubAuthMutation({ vaiables: {code} });
    } 
  }
  requestCode() {
    var clientID = "";
    window.location = `http://github.com/login/oauth/authorize?client_id=${clientID}&scope=user`;
  }
  render() {
    return (
      // update: 뮤테이션 끝난 후 실행할 함수
      <Mutation mutation={GITHUB_AUTH_MUTATION} update={this.authorizationComplete} refetchQueries={[{query: ROOT_QUERY}]}>
        {
          mutation => {
            this.githubAuthMutation = mutation
            return <Me signingIn={this.state.signingIn} requestCode={this.requestCode} logout={() => {
              localStorage.removeItem('token')
              let data = this.props.client.readQuery({ query: ROOT_QUERY });
              data.me = null;
              this.props.client.writeQuery({ query: ROOT_QUERY, data});
            }} />
          }
        }
      </Mutation>
    )
  }
}

export default compose(withApollo, withRouter)(AuthorizedUser);