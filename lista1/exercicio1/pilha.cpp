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
void Pilha::push(int value){
    if(topo_ == tam_-1){

        cout << "Pilha cheia" << endl;
        int * aux;
        aux = new int[++tam_];
        *aux = *vet_;
        vet_ = aux;
        vet_[++topo_] = value;
        delete [] aux;
    }
    else{
        vet_[++topo_] = value;
    }

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