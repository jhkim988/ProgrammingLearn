module.exports = {
  postPhoto: async (parent, args, { db, currentUser }) => {
    if (!currentUser) {
      throw new Error("Only an authroized user can post a photo");
    }
    var newPhoto = {
      ...args.input,
      userID: currentUser.githubLogin,
      created: new Date(),
    }
    const { insertedIds } = await db.collection('photo').insert(newPhoto);
    newPhoto.id = insertedIds[0]
    return newPhoto;
  },
  githubAuth: require('../auth/githubAuth'),
}