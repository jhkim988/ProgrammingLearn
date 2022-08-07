import { useQuery, gql } from '@apollo/client';

const allUsers = gql`
  query {
    allUsers {
      name
    }
  }
`
const Test = () => {
  const {data} = useQuery(allUsers);
  console.dir(data);
  return (
    <div>
      {data.allUsers.map((u) => <ul>u.name</ul>)}
    </div>
  )
}
export default Test;