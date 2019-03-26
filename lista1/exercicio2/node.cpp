// MyCode
#include "node.hpp"

    //Constructors
    Node::Node(int value)
        : value_(value)
    {
    }

/*    Node::Node(int value, Node previous , Node next ){
        value_ = value;
        previous_ = previous;
        next_ = next;
    }
*/ 
    //Methods

    int Node::value() const
    {
        return value_;
    }

    const Node& Node::previous() const
    {
        return previous_;
    }
    
    const Node& Node::next() const
    {
        return next_;
    }

    void Node::setPrevious(Node node){
        previous_ = node;
    }

    void Node::setNext(Node node){
        previous_ = node;
    }
 