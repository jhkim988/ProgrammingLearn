import { gql } from '@apollo/client';

export const LISTEN_FOR_USERS = gql`
  subscription {
    newUser {
      githubLogin
      name
      avatar
    }
  }
`

const Subscription = () => (
  <Subscription subscription={LISTEN_FOR_USERS}>
    {({ data, loading }) => loading ?
      <p>loading a new user...</p> :
      <div>
        <img src={data.newUser.avatar} alt=""/>
        <h2>{data.newUser.name}</h2>
      </div> 
    }
  </Subscription>
)

export default Subscription;