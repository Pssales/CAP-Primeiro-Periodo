#ifndef __LISTA_HPP__
#define __LISTA_HPP__

#include <iostream>

//My Code
#include "no.cpp"

class Lista
{
    public:
 
        // Constructor
        Lista();
 
        // Methods or Member Functions 

        int front();
        int back();

        void push_front(int value);
        void push_back(int value);

        void pop_front();
        void pop_back();
        
        void exibeLista();
 
    private:
 
        // Properties or Attributes or Data Members
        No *front_ = NULL;
        No *back_ = NULL;   
};
 
#endif // __LISTA_HPP