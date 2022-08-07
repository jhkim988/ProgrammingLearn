import fetch from 'node-fetch';

const requestGithubToken = credentials => fetch("https://github.com/login/oauth/access_token",
  {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Accept: "application/json",
    },
    body: JSON.stringify(credentials)
  })
  .then(res => res.json())
  .catch(error => {
    throw new Error(JSON.stringify(error));
  });
const requestGithubUserAccount = token => fetch(`https://api.github.com/user`, {
  method: "GET",
  headers: {
    Accept: "application/vnd.github+json",
    Authorization: `token ${token}`,
  }})
  .then(res => res.json())
  .catch(error => {
    throw new Error(JSON.stringify(error));
  });
const authorizeWithGithub = async credentials => {
  const { access_token } = await requestGithubToken(credentials);
  const githubUser = await requestGithubUserAccount(access_token);
  return {...githubUser, access_token}
}

const githubAuth = async (parent, { code }, { db, pubsub }) => {
  let {
    message,
    access_token,
    avatar_url,
    login,
    name
  } = await authorizeWithGithub({
    client_id: process.env.CLIENT_ID,
    client_secret: process.env.CLIENT_SECRET,
    code,
  });
  if (message) {
    throw new Error(message);
  }

  let latestUserInfo = {
    name,
    githubLogin: login,
    githubToken: access_token,
    avatar: avatar_url,
  }

  const { upsertedId } = await db
    .collection('users')
    .replaceOne({githubLogin: login}, latestUserInfo, {upsert: true});
  const user = await await db.collection('users').findOne({ githubLogin: login })
  upsertedId && pubsub.publish('new-user', { newUser: user })
  return {
    user,
    token: access_token
  };
};

export default githubAuth;