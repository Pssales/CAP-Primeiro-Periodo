#ifndef __NODE_HPP__
#define __NODE_HPP__
 
//My code
#include "node.hpp"

class Node
{
     public:

        //Constructors
        Node(int value= 0);
        Node(int value= 0, Node previous, Node next);
 
        //Methods
        int value() const;

        const Node& previous() const;
        const Node& next() const;

     private:
 
        int value_;
        Node previous_;
        Node next_;
};

#endif // __NODE_HPP__