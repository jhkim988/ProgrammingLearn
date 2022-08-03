const requestGithubToken = credentials => fetch("http://github.com/login/oauth/access_token",
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
const requestGithubUserAccount = token => fetch(`http://api.github.com/user?access_token=${token}`)
  .then(toJSON)
  .catch(throwError);
const authorizeWithGithub = async credentials => {
  const { access_token } = await requestGithubToken(credentials);
  const githubUser = await requestGithubUserAccount(access_token);
  return {...githubUser, access_token}
}

const githubAuth = async (parent, { code }, { db }) => {
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
    avartar: avatar_url,
  }

  const {
    ops: [user]
  } = await db
    .collections("users")
    .replaceOne({githubLogin: login}, latestUserInfo, {upsert: true});
  
  return { user, token: access_token };
};

module.exports = githubAuth;