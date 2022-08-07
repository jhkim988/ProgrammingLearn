import fetch from 'node-fetch';
import githubAuth from '../auth/githubAuth.js';
import path from 'path';
import fs  from 'fs';
import { finished } from 'stream';

const Mutation = {
  uploadPhoto: async (parent, { file }) => {
    const { createReadStream, filename, mimetype, encoding } = await file;
    const saveName = (new Date()).toISOString().replace(/[^0-9]/g, "")+filename.replace(/[.\s]/g, "")+'.jpg';
    const toPath = path.join(path.resolve(), 'assets', 'photos', `${saveName}`);
    const stream = createReadStream();
    const out = fs.createWriteStream(toPath);
    await stream.pipe(out);
    await finished(out, () => {});
    return {filename: saveName, mimetype, encoding};
  },
  postPhoto: async (parent, args, { db, currentUser, pubsub }) => {
    if (!currentUser) {
      throw new Error("Only an authroized user can post a photo");
    }
    var newPhoto = {
      ...args.input,
      userID: currentUser.githubLogin,
      created: new Date(),
    }
    const { insertedIds } = await db.collection('photos').insert(newPhoto);
    newPhoto.id = insertedIds[0]
    pubsub.publish('photo-added', { newPhoto });
    return newPhoto;
  },
  githubAuth,
  addFakeUsers: async (parent, { count }, { db, pubsub }) => {
    var randomUserApi = `http://randomuser.me/api/?results=${count}`
    var { results } = await fetch(randomUserApi).then(res => res.json());
    var users = results.map(r => ({
      githubLogin: r.login.username,
      name: `${r.name.first} ${r.name.last}`,
      avatar: r.picture.thumbnail,
      githubToken: r.login.sha1,
    }));
    await db.collection('users').insert(users);
    users.forEach(newUser => pubsub.publish('new-user', { newUser }));
    return users;
  },
  fakeUserAuth: async (parent, { githubLogin }, { db }) => {
    var user = await db.collection('users').findOne({ githubLogin });
    if (!user) {
      throw new Error(`Cannot find user with githubLogin "${ githubLogin }"`);
    }
    return {
      user,
      token: user.githubToken,
    }
  }
}

export default Mutation;