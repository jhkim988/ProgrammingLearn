const { GraphQLScalarType } = require('graphql');

module.exports = {
  Photo: {
    id: parent => parent.id || parent._id,
    url: parent => `/img/photos/${parent._id}.jpg`,
    postedBy: async (parent, args, { db }) => {
      return await db.collection('users').findOne({ githubLogin: parent.userID });
    },
    taggedUsers: parent => {
      return tags.filter(tag => tag.photoID == parent.id)
        .map(tag => tag.userID)
        .map(userID => users.find(u => u.githubLogin == userID));
    },
  },  
  User: {
    postedPhotos: parent => {
      return photos.filter(p => p.githubLogin==parent.githubLogin);
    },
    inPhotos: parent => {
      return tags.filter(tag => tag.userID == parent.id)
        .map(tag => tag.photoID)
        .map(photoID => photos.find(p => p.photoID == photoID));
    },
  },
  DateTime: new GraphQLScalarType({
    name: 'DateTime',
    description: 'A valid date time value.',
    parseValue: value => new Date(value),
    serialize: value => (new Date(value)).toISOString(),
    parseLiteral: ast => ast.value,
  })
}