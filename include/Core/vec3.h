#pragma once

#include <SDL.h>
#include <iostream>
using namespace std;

class Vec3 {
    public:

    float x,y,z;
    Vec3(float x, float y, float z);

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

    // ostream
    ostream& operator<<(ostream& os) const;

};

