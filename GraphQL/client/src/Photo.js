import React, { Fragment } from 'react';
import { useQuery } from '@apollo/client'
import { ROOT_QUERY } from './App';

const Photos = () => {
  const { loading, error, data, refetch } = useQuery(ROOT_QUERY);
  if (loading) return <p>loading...</p>;
  return (
    <Fragment>
    <button onClick={() => refetch()}>사진 다시 가져오기</button>
    {data.allPhotos.map((photo) => <img key={photo.id} src={`http://localhost:4000${photo.url}`} alt={photo.name} width={350} />)}
    </Fragment>
  )
  
}

export default Photos;