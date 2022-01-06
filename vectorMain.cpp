#include <iostream>
#include "Vec3.h"

int main()
{
    Vec3 vec0(3, 5, 1);
    Vec3 vec1(8,2,5);

    std::cout << Vec3::cross(vec0, vec1);

    return 0;

}
