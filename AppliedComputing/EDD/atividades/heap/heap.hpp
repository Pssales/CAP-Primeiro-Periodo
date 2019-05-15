#ifndef __Heap__HPP__
#define __Heap__HPP__


#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Heap {
    public:
        Heap();

        void inserir(T );
        void remover();

    //  Métodos de manipulação
        void moveUp();
        void moveDown();
        void troca(int filho, int pai);

        
    // Retorna a posição dos elementos
        int getPai(int i);
        int filhoDireita(int i);
        int filhoEsquerda(int i);

    // Retorna o valor presente na raiz   
        T root();
        
    // Retorna a quantidade nós atual da arvore
        int tamanho();
    // Retorna a capacidade da árvore
        int capacidade();
    // Atribui o valor de capacidade
        void setCapacidade(int& n);
        
        vector<T> elementos_;
        int capacidade_;
        
    
    private:
    //Boqueio de construtor e atribuição
        Heap(Heap&);
        Heap& operator=(Heap&);

};

template <class T>
Heap<T> :: Heap(){
}



template <class T>
void Heap<T> :: inserir(T value) {
  elementos_.push_back(value);
  moveUp();
}

template <class T>
void Heap<T> :: remover() {

  if(elementos_.size() != 0){
    int filho = elementos_.size()  - 1;
    troca(filho, 0);
    
    T value = elementos_.back();
    elementos_.pop_back();
    
    moveDown();
  }else{
      cout << "Nao existem mais valores para serem removidos."<< endl;
  }

}

template <class T>
void Heap <T>:: moveUp() {
  int filho = elementos_.size() - 1;
  int pai = getPai(filho);
  
  while (elementos_[filho] > elementos_[pai] && filho >=0 && pai >= 0) {
	
	troca(filho, pai);
	filho = pai;
	pai = getPai(filho);
  }
}


template <class T>
void Heap<T> :: moveDown() {
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
	}
	else 
	  break;
  }
}

template <class T>
void Heap<T>::troca(int filho, int pai) {
  T temp;
  temp = elementos_[filho];
  elementos_[filho] = elementos_[pai];
  elementos_[pai] = temp;
}


template <class T>
int Heap<T> :: getPai(int filho) {
    return (filho % 2 == 0)?(filho /2 ) -1 : filho/2  ;
}

template <class T>
int Heap<T> :: filhoDireita(int pai){
  return 2 * pai + 2;
}

template <class T>
int Heap<T> :: filhoEsquerda(int pai){
  return 2*pai +1;
}


template <class T>
T Heap<T> :: root() {
	return elementos_[0];
}


template <class T>
int Heap<T>::tamanho(){
  return elementos_.size();
}

template <class T>
int Heap<T>::capacidade(){
  return capacidade_;
}
template <class T>
void Heap<T>::setCapacidade(int& n){
   capacidade_ = n;
}


#endif
