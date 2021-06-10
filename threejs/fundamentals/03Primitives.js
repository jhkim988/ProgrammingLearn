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

        // initial rot
        thing.rotX = 0.5;
        thing.rotY = 0.5;

        const controls= new DragControls([obj], thing.camera, thing.renderer.domElement);
        
        const start = {x : 0, y : 0};
        controls.addEventListener("dragstart", e => {
            start.x = e.object.position.x;
            start.y = e.object.position.y;

            console.log('start: ', start.x, start.y)
        })
        controls.addEventListener("drag", e => {
            thing.rotX = e.object.position.x - start.x;
            thing.rotY = e.object.position.y - start.y;

            console.log('thing.rot', thing.rotX, thing.rotY);
        });

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

        thing.obj.rotation.y = thing.rotX * time * 0.001;
        thing.obj.rotation.x = thing.rotY * time * 0.001;

        thing.renderer.render(thing.scene, thing.camera);
        requestAnimationFrame(render);
    }
    requestAnimationFrame(render);
}

main();