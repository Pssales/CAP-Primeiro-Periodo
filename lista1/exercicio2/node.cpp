// MyCode
#include "node.hpp"

Node::Node(int value)
    : value_(value)
{
}

const Node& previous()
{
    return previous_;
}
 
const Node& next()
{
    return next_;
}
 
void Node::translate(double x, double y)
{
    x_ += x;
    y_ += y;
}
 
double Node::distance(const Node& other) const
{
    double dx = x_ - other.x_;
    double dy = y_ - other.y_;
 
    double d = std::sqrt(dx*dx  + dy*dy);
    return d;
}