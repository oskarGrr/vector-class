#include <cmath>
#include <iostream>
#include "Vec3.h"

//probably a lot of stuff missing 
//that it could have. Just a simple
//class for simple tasks

//default ctor to zero init members
Vec3::Vec3() : x(0), y(0), z(0) {}
    
//ctor for instiating with given values
Vec3::Vec3(const double x, const double y, const double z)
: x(x), y(y), z(z) {}

//copy constructor
Vec3::Vec3(const Vec3& other)
: x(other.x), y(other.y), z(other.z) {}

//copy assign
Vec3& Vec3::operator = (const Vec3& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Vec3 Vec3::operator + (const Vec3& rhs)
{
    return Vec3(x+rhs.x, y+rhs.y, z+rhs.z);
}

Vec3 Vec3::operator - (const Vec3& rhs)
{
    return Vec3(x-rhs.x, y-rhs.y, z-rhs.z);
}

Vec3& Vec3::operator -= (const Vec3& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vec3& Vec3::operator += (const Vec3& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

//compare two vectors
bool Vec3::operator == (const Vec3& rhs)
{
    return (
            x == rhs.x &&
            y == rhs.y &&
            z == rhs.z
           );
}

//scale *this 
void Vec3::scale(const double scaler)
{
    x *= scaler;
    y *= scaler;
    z *= scaler;
}


//get the length^2 of *this
double Vec3::magnitudeSqrd()
{
    return x*x + y*y + z*z;
}

//get the true length of the *this
double Vec3::magnitude()
{
    return sqrt(x*x + y*y + z*z);
}    

//normalize *this
void Vec3::normalize()
{
    double magnitude;
    magnitude = sqrt((x*x)+(y*y)+(z*z));
    x /= magnitude;
    y /= magnitude;
    z /= magnitude; 
}

//return new vector that is a normalized 
//version of the vector passed in
Vec3 Vec3::normalize(const Vec3& v)
{
    double magnitude;
    magnitude = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    return Vec3(v.x/magnitude, v.y/magnitude, v.z/magnitude);
}

//dot product of two Vec3s
double Vec3::dot(const Vec3& v0, const Vec3& v1)
{
    return (v0.x * v1.x)+(v0.y * v1.y)+(v0.z * v1.z);
}

//cross product of two Vec3s
Vec3 Vec3::cross(const Vec3& v0, const Vec3& v1)
{
    return {
            v0.y*v1.z - v0.z*v1.y,
            v0.z*v1.x - v0.x*v1.z,
            v0.x*v1.y - v0.y*v1.x
           };
}

std::ostream& operator << (std::ostream& os, const Vec3& v)
{
    std::cout << v.x << ' ' << v.y << ' ' << v.z;
    return os;
}
