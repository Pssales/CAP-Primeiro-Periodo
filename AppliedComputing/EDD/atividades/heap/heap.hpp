#ifndef __HEAP__HPP__
#define __HEAP__HPP__

#include <iostream>
#include <vector> 

using namespace std;

template <class Template>
class Heap {
    public:
        Heap();

        void inserir(Template );
        void remover();

    //  Métodos de manipulação
        void moveUp();
        void moveDown();
        void troca(int filho, int pai);

        
    // Retorna a posição dos elementos
        int getPai(int i);
        int filhoDireita(int i);
        int filhoEsquerda(int i);
        int getFilhoDireita(int i);
        int getFilhoEsquerda(int i);

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

template <class Template>
Heap<Template>::Heap(){
}


template <class Template>
void Heap<Template>::inserir(Template valor) {
    elementos_.push_back(valor);
    moveUp();
}

template <class Template>
void Heap<Template>::remover() {

    if(elementos_.size() != 0){
        int filho = elementos_.size()  - 1;
        troca(filho, 0);
        
        Template valor = elementos_.back();
        elementos_.pop_back();
        
        moveDown();
    }else{
        cout << "Nao existem mais valores para serem removidos."<< endl;
    }

}


template <class Template>
void Heap<Template>::moveUp() {
    int filho = elementos_.size() - 1;
    int pai = getPai(filho);
    
    while (elementos_[filho] > elementos_[pai] && filho >=0 && pai >= 0) {
        troca(filho, pai);
        filho = pai;
        pai = getPai(filho);
    }
}


template <class Template>
void Heap<Template>::moveDown() {
    int pai = 0;

    while (true) {
        int esquerda = filhoEsquerda(pai);
        int direira = filhoDireita(pai);
        int tamanho = elementos_.size();
        int maior = pai;

        if (esquerda < tamanho && elementos_[esquerda] > elementos_[maior])
            maior = esquerda;

        if (direira < tamanho && elementos_[direira] > elementos_[maior])
            maior = direira;

        if (maior != pai) {
            troca(maior, pai);
            pai = maior;
        }else{
            break;
        }

    }
}

template <class Template>
void Heap<Template>::troca(int filho, int pai) {
    Template temp;
    temp = elementos_[filho];
    elementos_[filho] = elementos_[pai];
    elementos_[pai] = temp;
}


template <class Template>
int Heap<Template>::getPai(int filho) {
    return (filho % 2 == 0)?(filho /2 ) -1 : filho/2  ;
}

template <class Template>
int Heap<Template>::filhoDireita(int pai){
    return 2 * pai + 2;
}

template <class Template>
int Heap<Template>::filhoEsquerda(int pai){
    return 2*pai +1;
}

template <class Template>
int Heap<Template>::getFilhoDireita(int pai){
    if (elementos_.size() > (2 * pai + 2))
    {
        return elementos_[2 * pai + 2];
    }else{
        cout << "Não existe filho a direita"<< endl;
    }
    
}

template <class Template>
int Heap<Template>::getFilhoEsquerda(int pai){
     if (elementos_.size() > (2 * pai + 2))
    {
        return elementos_[2*pai +1];
    }else{
        cout << "Não existe filho a esquerda"<< endl;
    }
}


template <class Template>
Template Heap<Template>::root() {
	return elementos_[0];
}


template <class Template>
int Heap<Template>::tamanho(){
    return elementos_.size();
}

template <class Template>
int Heap<Template>::capacidade(){
    return capacidade_;
}

template <class Template>
void Heap<Template>::setCapacidade(int& n){
    capacidade_ = n;
}


#endif
