#ifndef VECTOR_3
#define VECTOR_3
#include <iostream>

//probably a lot of stuff missing 
//that it could have. Just a simple
//class for simple tasks

class Vec3
{
public:
    double x,y,z;
    
    //default ctor to zero init members
    Vec3();

    //ctor for constructing with given values
    Vec3(const double,const double,const double);

    //copy ctor
    Vec3(const Vec3&);

    //copy assign
    Vec3& operator = (const Vec3&);

    //compare two vectors
    bool operator == (const Vec3&);
    
    //add two Vec3s
    Vec3 operator + (const Vec3&);

    //subtract two vectors
    Vec3 operator - (const Vec3&);

    Vec3& operator -= (const Vec3&);

    Vec3& operator += (const Vec3&);

    //scale *this 
    void scale(const double);

    //length of *this^2
    double magnitudeSqrd();

    //length of *this
    double magnitude();

    //normalize *this
    void normalize();
    
    //return new Vec3 that is normalized
    //version of the Vec3 passed in
    static Vec3 normalize(const Vec3&);
    
    //dot product of two Vec3s
    static double dot(const Vec3&, const Vec3&);

    //cross product of two Vec3s
    static Vec3 cross(const Vec3&, const Vec3&);

};//class Vec3

//free func for printing a vec3
std::ostream& operator << (std::ostream&, const Vec3&);

#endif
