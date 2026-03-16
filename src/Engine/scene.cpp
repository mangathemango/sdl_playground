#include <scene.h>
#include <mat4.h>
#include <meshrenderer.h>
#include <SDL.h>

void Scene::render() {
    std::cout << "Rendering " << objs.size() << std::endl;
    if (mainCamera == nullptr) {
        return;
    }
    Transform* cameraTf = mainCamera->parent->getComponent<Transform>();
    std::vector<Vec3> vertices;
    std::vector<int> indices;
    for (GameObj* obj: objs) {
        std::cout << *obj << std::endl;
        MeshRenderer* mr = obj->getComponent<MeshRenderer>();        
        Transform* tf = obj->getComponent<Transform>();  
        
        if (mr == nullptr || tf == nullptr) {
            continue;
        }
        Mat4 transformation = Mat4();

        transformation = transformation
            .translate(tf->position)
            .rotate(tf->rotation)
            .scale(tf->scale) // transform the vertex wrt the object's orientation
            .translate(-cameraTf->position)
            .rotate(cameraTf->rotation.inverse()); // wrt the camera's orientation
        
        for (Vec3& vertex: mr->mesh.vertices) {
            Vec3 transformed = transformation * vertex;
            std::cout << transformed << std::endl;
            vertices.push_back(transformed);
        }
    }
}