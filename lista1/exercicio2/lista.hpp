#ifndef __LISTA_HPP__
#define __LISTA_HPP__
 
#include "node.hpp"
class Lista
{
    public:
 
        // Constructor
        Lista();
 
        // Methods or Member Functions 
        const Node& fim() const;
 
        const Node& inicio() const;

        void push_front(Node node);
        void push_back(Node node);

        void pop_front();
        void pop_back();
 
    private:
 
        // Properties or Attributes or Data Members
        Node inicio_;
        Node fim_;
        int length_;
        
};
 
#endif // __LISTA_HPP__