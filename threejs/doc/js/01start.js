const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera( 75, window.innerWidth / window.innerHeight, 0.1, 1000 );
// three.js 여러 종류의 camera
// PerspectiveCamera(시야각(FOV), 종횡비(aspect ratio), near, far);
// near: near보다 가까이 있는 것은 렌더링 되지 않는다.
// far: far보다 멀리 있는 것은 렌더링 되지 않는다.

const renderer = new THREE.WebGLRenderer();
// 오래된 브라우저가 WebGL을 지원하지 않을 때 대비용

renderer.setSize( window.innerWidth, window.innerHeight );
// renderer 인스턴스를 생성할 때 렌더링할 곳의 크기를 설정해야한다.
// setSize(width, height, true/false);
// 사이즈는 유지하고, 낮은 해상도로 불러오고 싶을 때: false

document.body.appendChild( renderer.domElement );

const geometry = new THREE.BoxGeometry(); // cube를 만든다.
const material = new THREE.MeshBasicMaterial( { color: 0x00ff00 } ); // 색을 변경한다.
const cube = new THREE.Mesh( geometry, material ); // material을 geometry에 적용한다.
scene.add( cube ); // 추가한다. (0, 0, 0)

camera.position.z = 5; // 카메라를 조금 움직인다.

// render or animate loop
function animate() {
    requestAnimationFrame( animate );

    cube.rotation.x += 0.01;
    cube.rotation.y += 0.01;

    renderer.render( scene, camera );
}
animate();