// MyCode
#include "point.hpp"
 
// C++ Standard Library
#include <iostream>
 
int main()
{
	
	Point p1(-1.0, -1.0);
 
    Point p2(1.0, 1.0);
 
    double d = p1.distance(p2);
 
    std::cout << d << std::endl;
 
    return 0;

}