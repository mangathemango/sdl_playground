#include <component.h>
#include <mesh.h>

struct MeshRenderer: public Component {
    Mesh* mesh;
    // furture todo: Material maybe?
};