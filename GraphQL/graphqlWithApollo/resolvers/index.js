import Query from './Query.js';
import Mutation from './Mutation.js';
import Subscription from './Subscription.js';
import Type from './Type.js';
import GraphQLUpload from 'graphql-upload/GraphQLUpload.mjs'

const resolvers = {
  Upload: GraphQLUpload,
  Query,
  Mutation,
  Subscription,
  ...Type
}


export default resolvers;