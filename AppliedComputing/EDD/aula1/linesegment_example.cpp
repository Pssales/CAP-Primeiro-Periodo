// MyCode
#include "linesegment.hpp"
 
// C++ Standard Library
#include <iostream>
 
int main()
{
    Point p1(-1.0, -1.0);
    Point p2(1.0, 1.0);
 
    LineSegment s(p1, p2);
 
    Point p3(1.0, 0.0);
 
    bool result = s.contains(p3);
 
    std::cout << result << std::endl;
 
 /*   Point p4(0.0, 1.0);
 
    LineSegment t(p3, p4);
 
    result = s.intersects(t);
 
    std::cout << result << std::endl;
 */
    return 0;
}