#ifndef __POINT_HPP__
#define __POINT_HPP__
 
class Point
{
    public:
 
        // Constructor
        Point(double x = 0.0, double y = 0.0);
 
 
        // Methods or Member Functions 
        double x() const;
 
        double y() const;
 
        void translate(double x, double y);
 
        double distance(const Point& other) const;
 
    private:
 
        // Properties or Attributes or Data Members
        double x_;
        double y_;
};
 
#endif // __POINT_HPP__