//My code
#include "pilha.hpp"

// C++ Standard Library
#include <iostream>

using namespace std;

Pilha::Pilha(){
    vet_ = new int[100];
    max_tam_ = 99;
    topo_ = -1;
}

Pilha::~Pilha()
{
    delete[] vet_;
}

//Methods
void Pilha::push(int value){
    if(topo_ == max_tam_)
        cout << "Pilha cheia" << endl;
    else
        vet_[++topo_] = value;

}

void Pilha::pop(){
    if(topo_ == -1)
        cout << "Pilha vazia" << endl;
    else
        topo_--;
}

int Pilha::top(){
    if(topo_ != -1)
        return vet_[topo_];
    else
        return -1;
}

bool Pilha::empty(){
    return (topo_ == -1);
}