const Query = {
  totalPhotos: (parent, args, { db }) =>
    db.collection('photos').estimatedDocumentCount(),
  allPhotos: (parent, args, { db }) => 
    db.collection('photos').find().sort({created: -1}).toArray(),
  totalUsers: (parent, args, { db }) => 
    db.collection('users').estimatedDocumentCount(),
  allUsers: (parent, args, { db }) => 
    db.collection('users').find().toArray(),
  me: (parent, args, { currentUser }) => currentUser,
}
export default Query;