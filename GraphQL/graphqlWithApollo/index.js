const { ApolloServer } = require('apollo-server')

const typeDefs = `
  enum PhotoCategory {
    SELFIE
    PORTRAIT
    ACTION
    LANDSCAPE
    GRAPHIC
  }
  type User {
    githubLogin: ID!
    name: String
    avartar: String
    postedPhotos:[Photo!]!
  }
  type Photo {
    id: ID!
    url: String!
    name: String!
    decription: String
    category: PhotoCategory!
    postedBy: User!
  }
  type Query {
    totalPhotos: Int!
    allPhotos: [Photo!]!
  }

  input PostPhotoInput {
    name: String!
    category: PhotoCategory=PORTRAIT
    decription: String
  }

  type Mutation {
    postPhoto(input: PostPhotoInput!): Photo!
  }
`
var _id = 0;
var photos = [];
var users = [
  {
    githubLogin: `gg`,
    name: `jinhan`
  }
];
var photos = [
  {
    id: `1`,
    name: `Sad Dear`,
    description: `Let me have no shame under heaven 'til I die`,
    category: `PORTRAIT`,
    githubUser: `gPlake`,
  }
]

const resolvers = {
  Query: {
    totalPhotos: () => photos.length,
    allPhotos: () => photos,
  },
  Mutation: {
    postPhoto: (parent, args) => {
      var newPhoto = {
        id: _id++,
        ...args.input
      }
      photos.push(newPhoto);
      return newPhoto;
    } 
  },

  // trivial type
  Photo: {
    url: parent => `http://yoursite.com/img/${parent.id}.jpg`,
    postedBy: parent => {
      return users.find(u => u.githubLogin==parent.githubUser)
    }
  },

  User: {
    postedPhoto: parent => {
      return photos.filter(p => p.githubLogin==parent.githubLogin);
    },
  },
}

const server = new ApolloServer({typeDefs, resolvers});

server
  .listen()
  .then(({url}) => console.log(`GraphQL Service running on ${url}`));