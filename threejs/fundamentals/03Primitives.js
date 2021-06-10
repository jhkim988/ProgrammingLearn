import * as THREE from './three.module.js'
import { DragControls } from './DragControls.js';

function main() {
    const fov = 75;
    const aspect = 2;
    const near = 0.1;
    const far = 5;

    const lightcolor = 0xFFFFFF;
    const intensity = 1;
    const light = new THREE.DirectionalLight(lightcolor, intensity);
    light.position.set(-1, 2, 4);

    function makeWindow(querySelector) {
        const canvas = document.querySelector(querySelector);
        const renderer = new THREE.WebGLRenderer({canvas});
        const camera = new THREE.PerspectiveCamera(fov, aspect, near, far);

        camera.position.z = 2;

        const scene = new THREE.Scene();
        scene.add(light);

        return {canvas, renderer, camera, scene};
    }

    function makeObject(querySelector, func, color, ...args) {
        const thing = makeWindow(querySelector);
        const geometry = new func(...args);
        const material = new THREE.MeshPhongMaterial({color});
        const obj = new THREE.Mesh(geometry, material);

        const windowHalfX = thing.renderer.clientWidth / 2;
        const windowHalfY = thing.renderer.clientHeight / 2;

        // initial rot
        thing.rotX = 0.5;
        thing.rotY = 0.5;

        const mouseDownEvent = e => {
            e.preventDefault();
            controls.addEventListener("mousemove", mouseMoveEvent, false);
            controls.addEventListener("mouseup", mouseUpEvent, false);
            controls.addEventListener("mouseout", mouseOutEvent, false);
        
            mouseXOnMouseDown = e.clientX - windowHalfX;
            targetRotationOnMouseDownX = targetRotationX;
    
            mouseYOnMouseDown = e.clientY - windowHalfY;
            targetRotationOnMouseDownY = targetRotationY;
        }
    
        const mouseMoveEvent = e => {
            mouseX = e.clientX - windowHalfX;
            targetRotationX = (mouseX - mouseXOnMouseDown);
            mouseY = e.clientY - windowHalfY;
            targetRotationY = (mouseY - mouseYOnMouseDown);
        }
    
        const mouseUpEvent = e => {
            controls.removeEventListener("mousemove", mouseMoveEvent, false);
            controls.removeEventListener("mouseup", mouseUpEvent, false);
            controls.removeEventListener("mouseout", mouseOutEvent, false);
        }
    
        const mouseOutEvent = e => {
            controls.removeEventListener("mousemove", mouseMoveEvent, false);
            controls.removeEventListener("mouseup", mouseUpEvent, false);
            controls.removeEventListener("mouseout", mouseOutEvent, false);
        }
        
        const controls = new DragControls([obj], thing.camera, thing.renderer.domElement);

        controls.addEventListener("mousedown", mouseDownEvent, false);
        thing.scene.add(obj);
        thing.obj = obj;
        return thing;
    }

    function resizeRendererToDisplaySize(renderer) {
        const canvas = renderer.domElement;
        const width = canvas.clientWidth;
        const height = canvas.clientHeight;

        const needResize = canvas.width !== width || canvas.height != height;
        if (needResize) {
            renderer.setSize(width,height, false);
        }

        return needResize;
    }

    const thing = makeObject("#box", THREE.BoxGeometry, 0xed82d4, 1, 1, 1);
    function render(time) {
        if (resizeRendererToDisplaySize(thing.renderer)) {
            const canvas = renderer.domElement;
            camera.aspect = canvas.clientWidth / canvas.clientHeight;
            camera.updateProjectionMatrix();
        }

        // thing.obj.rotation.x = thing.rotX * time * 0.001;
        thing.obj.rotation.y = thing.rotY * time * 0.001;

        thing.renderer.render(thing.scene, thing.camera);
        requestAnimationFrame(render);
    }
    requestAnimationFrame(render);
}

main();