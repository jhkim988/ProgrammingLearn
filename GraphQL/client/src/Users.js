import React from 'react';
import { useQuery, useMutation, gql } from '@apollo/client';
import { ROOT_QUERY } from './App'

const Users = () => {
  const {loading, error, data, refetch} = useQuery(ROOT_QUERY);
  if (error) return <p>{`Error! ${error.message}`}</p>;
  if (loading) return <p>사용자 불러오는 중...</p>;
  return <UserList count={data.totalUsers} users={data.allUsers} refetchUsers={refetch}/>;
}
// UserList의 attributes를 인자로 받는다.
const UserList = ({ count, users, refetchUsers }) => {
  const [addFakeUsers, {loading, error, data}] = useMutation(ADD_FAKE_USERS_MUTATION, {
    variables: { count: 1},
  });
  if (error) return <p>{`Error ${error.message}`}</p>
  return (
    <div>
      <p>{count} Users</p>
      <button onClick={() => refetchUsers()}>다시 가져오기</button>
      <button onClick={addFakeUsers}>임시 사용자 추가</button>
      <ul>
      {users.map(user => 
        <UserListItem key={user.githubLogin} name={user.name} avatar={user.avatar} />  
      )}
      </ul>
    </div>
  )
}

const UserListItem = ({ name, avatar }) => (
  <li>
    <img src={avatar} width={48} height={48} alt="" />
    {name}
  </li>
)

const ADD_FAKE_USERS_MUTATION = gql`
  mutation addFakeUsers($count:Int!) {
    addFakeUsers(count:$count) {
      githubLogin
      name
      avatar
    }
  }
`

const updateUserCache = (cache, { data: { addFakeUsers }}) => {
  let data = cache.readQuery({query: ROOT_QUERY});
  data.totalUsers += addFakeUsers.length;
  data.allUsers = [
    ...data.allUsers,
    ...addFakeUsers
  ];
  cache.writeQuery({ query: ROOT_QUERY, data });
}

export default Users