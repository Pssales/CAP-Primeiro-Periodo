//My code
#include "pilha.hpp"

// C++ Standard Library
#include <iostream>

using namespace std;

Pilha::Pilha(int tamanho){
    vet_ = new int[tamanho];
    tam_ = tamanho;
    topo_ = -1;
}

Pilha::~Pilha()
{
    delete[] vet_;
}

//Methods

/*void Pilha::push(int value){
    if(topo_ == tam_){
        cout << "Pilha cheia" << endl;
        cout << "topo" << topo_<< endl;
        cout << "tam_" << tam_ << endl;
        vet_ = new int[++tam_];
    }
    vet_[++topo_] = value;
}*/

void Pilha::push(int valor)
{
    if (topo_ > tam_){
        tam_+=1;
        vet_ = new int[tam_];
    }
    vet_[++topo_] = valor;
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