#pragma once
#include <concepts>
#include <iostream>
#include <string>

class Component {
    public:
    virtual void display(std::ostream& os) const;
};

template <typename T>
concept ComponentType = std::derived_from<T, Component>;

std::ostream& operator<<(std::ostream& os, const Component& component);