#ifndef __LINESEGMENGT_HPP__
#define __LINESEGMENGT_HPP__
 
// MyCode
#include "point.hpp"
 
class LineSegment
{
     public:
 
         LineSegment(const Point& p1, const Point& p2);
 
         const Point& first() const;
 
         const Point& second() const;
 
         bool contains(const Point& p) const;
 
        // bool intersects(const LineSegment& other) const;
 
 
     private:
 
         Point first_;
         Point second_; 
};
#endif // __LINESEGMENGT_HPP__