#pragma once

#include <SDL.h>
#include <iostream>
using namespace std;

class Vec3 {
    float x,y,z;
    
    public:
    Vec3(float x, float y, float z);
    Vec3 operator-() const;
    Vec3 operator+(const Vec3 &other) const;
    Vec3 operator-(const Vec3 &other) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;

    Vec3& operator+=(const Vec3 &other);
    Vec3& operator-=(const Vec3 &other);
    Vec3& operator*=(float scalar);
    Vec3& operator/=(float scalar);
    
    bool operator==(const Vec3 &other) const;
    bool operator!=(const Vec3 &other) const;


    ostream& operator<<(ostream& os) const;

};

