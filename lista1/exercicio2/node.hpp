#ifndef __NODE_HPP__
#define __NODE_HPP__
 
//My code
#include "node.hpp"

class Node
{
     public:

        //Constructors
        Node(int value= 0);
       // Node(int value= 0, Node previous = NULL, Node next = NULL);
 
        //Methods
        int value() const;

        const Node& previous() const;
        const Node& next() const;

        void setPrevious(Node node);
        void setNext(Node node);

     private:
 
        int value_;
        Node previous_;
        Node next_;
};

#endif // __NODE_HPP__