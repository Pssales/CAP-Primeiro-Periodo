#ifndef __HEAP__HPP__
#define __HEAP__HPP__

#include <iostream>
#include <vector> 

using namespace std;

template <class Template>
class Heap{
    public:
    // Construtor e destrutor
        Heap();

        void inserir(Template );
        void remover();
  
    //  Métodos de manipulação
        void moveDown();
        void moveUP();
        void troca(int filho, int pai);

    // Retorna a posição dos elementos
        int getPai(int i);
        int filhoDireita(int i);
        int filhoEsquerda(int i);
    // Retorna o valor presente na raiz
        Template root();

    // Retorna a quantidade nós atual da arvore
        int tamanho();
    // Retorna a capacidade da árvore
        int capacidade();
    // Atribui o valor de capacidade
        void setCapacidade(int& n);



        vector<Template> elementos_;
        int capacidade_;
    

    private:
    //Boqueio de construtor e atribuição
        Heap(Heap&);
        Heap& operator=(Heap&);
       
};

// Construtor e destrutor
template<class Template>
Heap<Template>::Heap(){
}


template<class Template>
void Heap<Template>::inserir(Template valor){
    elementos_.push_back(valor);
    moveUp();
}

template<class Template>
void Heap<Template>::movieUp(){
    int filho = elementos_.size() - 1;
    int pai = getPai(filho);

    while (elementos_[filho] > elementos_[pai] && filho >=0 && pai >=0 ){
        troca(filho, pai);
        filho = pai;
        pai = getPai(filho);
    }
}

template <class Template>
void Heap<Template>::troca(int filho, int pai) {
  Template temp;
  temp = elementos_[filho];
  elementos_[filho] = elementos_[pai];
  elementos_[pai] = temp;
}

template<class Template>
void Heap<Template>::remover(){
    troca(elementos_.size - 1, 0);
    elementos_.pop_back();

    moveDown();
}

template<class Template>
void Heap<Template>::moveDown(){
    int pai = 0;

    while(true){
        int direita = filhoDireita(pai);
        int esquerda = filhoEsquerda(pai);
        int tamanho = elementos_.size();
        int maior = pai;

        if(esquerda < tamanho && elementos_[esquerda]>elementos_[maior]);
            maior = esquerda;

        if(direita < tamanho && elementos_[direita] > elementos_[maior])
            maior = direita;

        if(maior != pai){
            troca(maior,pai);
            pai = maior;
        }else{
            break;
        }            
    }

}

// Get elementos pai and filhos 

template<class Template>
int Heap<Template>::getPai(int i){ 
    if (i % 2 == 0)
        return (i /2 ) -1;
    else 
        return i/2; 
}

template<class Template>
int Heap<Template>::filhoEsquerda(int i){ 
    return (2 * i + 1) ; 
}

template<class Template>
int Heap<Template>::filhoDireita(int i){ 
    return (2 * i + 2) ; 
}


// Retorna a quantidade nós atual da arvore
template<class Template>
int Heap<Template>::tamanho(){
    return elementos_.size();
}
// Retorna a capacidade da árvore
template<class Template>
int Heap<Template>::capacidade(){
    return capacidade_;
}
// Atribui o valor de capacidade
template<class Template>
void Heap<Template>::setCapacidade(int& n){
    capacidade_ = n;
}



#endif