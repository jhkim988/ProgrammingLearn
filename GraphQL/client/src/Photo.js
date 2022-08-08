import React, { Fragment, useState } from 'react';
import { gql, useQuery } from '@apollo/client'
import { ROOT_QUERY } from './App';

const LOAD_PHOTO = gql`
  query allPhotos($offset: Int, $limit: Int, ) {
    allPhotos(offset: $offset, limit: $limit) {
      id
      url
      name
    }
  }
`

const Photos = () => {
  const { loading, error, data, refetch } = useQuery(LOAD_PHOTO, { variables: { limit: 5, offset: 0 }});
  // refetch();
  if (loading) return <p>loading...</p>;
  return (
    <Fragment>
    <button onClick={() => refetch()}>사진 다시 가져오기</button>
    {data.allPhotos.map((photo) => <img key={photo.id} src={`http://localhost:4000${photo.url}`} alt={photo.name} width={350}/>)}
    </Fragment>
  )
  
}

export default Photos;