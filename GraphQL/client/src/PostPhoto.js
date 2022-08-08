import React, { useState } from 'react';
import { gql, useMutation } from '@apollo/client'
import { ROOT_QUERY } from './App';

const POST_PHOTO_MUTATION = gql`
  mutation postPhoto($input: PostPhotoInput!) {
    postPhoto(input: $input) {
      id
      name
      url
    }
  }
`
const UPLOAD_PHOTO = gql`
  mutation uploadPhoto($file: Upload!) {
    uploadPhoto(file: $file) {
      filename
    }
  }
`

const PostPhoto = (props) => {
  const [name, setName] = useState("");
  const [description, setDescription] = useState("");
  const [category, setCategory] = useState("PORTRAIT");
  const [saveFileName, setSaveFileName] = useState("");

  const updatePhotos = (cache, { data: { postPhoto }}) => {
    const prev = cache.readQuery({ query: ROOT_QUERY });
    const copy = { ...prev };
    copy.allPhotos = [postPhoto, ...prev.allPhotos];
    copy.totalPhotos = prev.totalPhotos+1;
    cache.writeQuery({
      query: gql`
        query {
          totalPhotos
          allPhotos
        }
      `,
      data: copy
    });
    window.location.href='/';
  }

  const [uploadPhoto] = useMutation(UPLOAD_PHOTO, {
    onCompleted: (data) => {
      setSaveFileName(data.uploadPhoto.filename);
    }
  });

  const fileChange = ({target: {validity, files: [file]}}) => {
    if (validity) {
      uploadPhoto({
        variables: { file },
        context: {
          headers: {'apollo-require-preflight': 'true'}      
        }
      });      
    }
  }
  const [postPhoto, {loading, error, data}] = useMutation(POST_PHOTO_MUTATION);
  const postPhotoClick = () => {
    postPhoto({
      variables: {
        input: {
        name,
        description,
        category,
        url: saveFileName
      }},
      update: updatePhotos,      
    });
  }
  if (error) {
    console.error(error);
  }
  return (
    <form onSubmit={e => e.preventDefault()} style={{
      display: 'flex',
      flexDirection: "column",
      justifyContent: "flex_start",
      alignItems: "flex-start"
    }}>
      <h1>Post a Photo</h1>
      <input 
        type="text"
        style={{margin: "10px"}}
        placeholder="photo name..."
        value={name}
        onChange={({target}) => setName(target.value)}/>
      <textarea 
        type="text"
        style={{margin: "10px"}}
        placeholder="photo description..."
        value={description}
        onChange={({ target }) => setDescription(target.value)}
      />
      <select
        value={category}
        style={{ margin: "10px"}}
        onChange={({target}) => setCategory(target.value)}>
        <option value="PORTRAIT">PORTRAIT</option>
        <option value="LANDSCAPE">LANDSCAPE</option>
        <option value="ACTION">ACTION</option>
        <option value="GRAPHIC">GRAPHIC</option>
      </select>
      <input 
        type="file"
        style={{margin: "10px"}}
        accept="image/jpeg"
        onChange={fileChange}
      />
      <div style={{margin: "10px"}}>
        <button onClick={postPhotoClick}>Post Photo</button>
        <button onClick={() => window.location = '/'}>Cancel</button>
      </div>
    </form>
  )
}

export default PostPhoto;