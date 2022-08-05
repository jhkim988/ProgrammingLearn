import React from 'react';
import { BrowserRouter } from 'react-router-dom';
import Users from './Users';
import { gql } from 'apollo-boost';
import AuthorizedUser from './AuthorizedUser'

export const ROOT_QUERY = gql`
  query allUsers
  totalUsers
    allUsers { ...userInfo }
    me { ...userInfo }
    fragment userInfo on User {
      githbuLogin
      name
      avatar
    }
`;

const App = () => {
  <BrowerRouter>
    <div>
      <AuthroizedUser />
      <Users />
    </div>  
  </BrowerRouter>
}
export default App;