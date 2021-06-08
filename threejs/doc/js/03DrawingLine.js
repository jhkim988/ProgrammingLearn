// import { Scene, PerspectiveCamera, WebGLRenderer, LineBasicMaterial, Vector3, BufferGeometry, Line } from 'three';

const renderer = new THREE.WebGLRenderer();
renderer.setSize( window.innerWidth, window.innerHeight );
document.body.appendChild( renderer.domElement );

const camera = new THREE.PerspectiveCamera( 45, window.innerWidth/window.innerHeight, 1, 500 );
camera.position.set( 0, 0, 100 );
camera.lookAt( 0, 0, 0 );

const scene = new THREE.Scene();

// 재질 정의
// 선의 재질: LineBasicMaterial, LineDashedMaterial
const material = new THREE.LineBasicMaterial( {color: 0x0000ff} );

// 꼭짓점
const points = [];
points.push(new THREE.Vector3(-10, 0, 0));
points.push(new THREE.Vector3(0, 10, 0));
points.push(new THREE.Vector3(10, 0, 0));

const geometry = new THREE.BufferGeometry().setFromPoints( points );

const line = new THREE.Line( geometry, material );
scene.add( line );
renderer.render(scene, camera);

function animate() {
    requestAnimationFrame( animate );
    renderer.render( scene, camera );
}
animate();