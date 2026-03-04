#pragma once

#include <SDL.h>
#include <iostream>
#include <format>
#include <cmath>

using namespace std;

class Vec3 {
    public:

    float x,y,z;
    Vec3(float x, float y, float z);

    // Operator overrides:
    // Basic operations
    Vec3 operator-() const;
    Vec3 operator+(const Vec3 &other) const;
    Vec3 operator-(const Vec3 &other) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;

    // Some syntax sugar operations
    Vec3& operator+=(const Vec3 &other);
    Vec3& operator-=(const Vec3 &other);
    Vec3& operator*=(float scalar);
    Vec3& operator/=(float scalar);

    // Equality
    bool operator==(const Vec3 &other) const;
    bool operator!=(const Vec3 &other) const;
    

    // Direction vector
    Vec3 up();
    Vec3 down();
    Vec3 right();
    Vec3 left();
    Vec3 forward();
    Vec3 backward();

    // More operations
    Vec3 cross(const Vec3 &other) const;
    Vec3 dot(const Vec3 &other) const;
    Vec3 normalize() const;
    float magnitude() const;
    float distance(const Vec3 &other) const;
    Vec3 lerp(const Vec3 &other, float t);
};

ostream& operator<<(ostream& os, const Vec3& v);