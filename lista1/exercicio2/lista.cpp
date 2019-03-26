#ifndef NULL
#define NULL 0
#endif

#include "lista.hpp"
#include "node.hpp"

#include <iostream>

// Constructor
Lista::Lista(){
    length_ = -1;
    inicio_ = NULL;
    fim_ = NULL;
}

// Methods or Member Functions 
const Node& Lista::inicio() const{
    return inicio_;
}

const Node& Lista::fim() const{
    return fim_;
}

void Lista::push_front(Node node) {
    if(length_ == -1){
        inicio_ = node;
        fim_ = node;
    }else{
        node.setNext(inicio_);
        inicio_.setPrevious(node);
        inicio_ = node;
    }
    length_++;
}

void Lista::push_back(Node node) {
    if(length_ == -1){
        inicio_ = node;
        fim_ = node;
    }else{
        node.setPrevious(fim_);
        fim_.setNext(node);
        fim_ = node;
    }
    length_++;
}



void Lista::pop_front() {
    if(length_ == -1){
        std::cout << "Lista Vazia" << std::endl;
    }else{
        inicio_ = inicio.next();
    }
    length_++;
}

void Lista::pop_back() {
    if(length_ == -1){
        std::cout << "Lista Vazia" << std::endl;
    }else{
        fim_ = fim_.previus();
    }
    length_++;
}



