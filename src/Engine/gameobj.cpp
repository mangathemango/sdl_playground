#include <gameobj.h>
#include <transform.h>

template <ComponentType T> T* GameObj::getComponent() {
    return (T*) components[typeid(T).hash_code()];
}

template <ComponentType T> T* GameObj::addComponent() {
    Component* component = new T();
    components.insert({typeid(T).hash_code(), component});
    
    return getComponent<Transform>();
}

GameObj::GameObj() {
    addComponent<Transform>();
}

std::ostream& operator<<(std::ostream& os, const GameObj& obj) {
    os << "GameObj:\n";
    os << "- Components:\n";
    for (auto it = obj.components.begin(); it != obj.components.end(); it++) {
        os << *(it->second);
    }
    return os;
}


