// MyCode
#include "linesegment.hpp"
 
LineSegment::LineSegment(const Point& p1, const Point& p2)
    : first_(p1),
      second_(p2)
{
}
 
const Point& LineSegment::first() const
{
    return first_;
}
 
const Point& LineSegment::second() const
{
    return second_;
}
 
bool LineSegment::contains(const Point& p) const
{
    return true;
}
