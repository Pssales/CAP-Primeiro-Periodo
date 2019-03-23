// MyCode
#include "point.hpp"
 
// C++ Standard Library
#include <cmath>
 
Point::Point(double x, double y)
    : x_(x), y_(y)
{
}
 
double Point::x() const
{
    return x_;
}
 
double Point::y() const
{
    return y_;
} 
 
void Point::translate(double x, double y)
{
    x_ += x;
    y_ += y;
}
 
double Point::distance(const Point& other) const
{
    double dx = x_ - other.x_;
    double dy = y_ - other.y_;
 
    double d = std::sqrt(dx*dx  + dy*dy);
    return d;
}