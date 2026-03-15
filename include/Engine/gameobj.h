#pragma once
#include <component.h>
#include <concepts>
#include <unordered_map>
#include <optional>
#include <iostream>

class GameObj {
    public:
    std::unordered_map<size_t, Component*> components;
    GameObj();

    template <ComponentType T> T* addComponent();
    template <ComponentType T> T* getComponent();
};

std::ostream& operator<<(std::ostream& os, const GameObj& obj);