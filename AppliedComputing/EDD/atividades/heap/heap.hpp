#ifndef __HEAP__HPP__
#define __HEAP__HPP__

#include <iostream>
#include <vector> 
using std::vector;

template <class T>
class Heap{
    public:
        Heap(int n);
        ~Heap();
        void remove();
        T top() const; 
    //Inserção
    void ConstroiHeap(T valor);

    //Remoção
        void FixDownHeap(int n, int pos);
        void ExtraiHeap();

    private: 
        vector<T> elementos_;
        int n_;
        //Boqueio de construtor e atribuição
        Heap(Heap&);
        Heap& operator=(Heap&);
};

template<class T>
Heap<T>::Heap(int n){
    n_ = n;
}

template<class T>
Heap<T>::~Heap(){
    clear(elementos_);
}

template<class T>
Heap<T>::insert(T valor){
}

template<class T>
Heap<T>::remove(T valor){
    
}

template<class T>
void ExtraiHeap()
{
    for(int i = 1; i <= n; ++i)
    {
        int max = elementos_[1];
        elementos_[1] = elementos_[n – i + 1];
        FixDownHeap( n - i, 1);
    }
}

template<class T>
void FixDownHeap(int n, int pos){
    int v = elementos_[pos];
    int j = 2 * pos;
    while(j <= n){
        if((j < n) && (A[j] < elementos_[j + 1]))
            ++j;
        if(v > elementos_[j])
            break;

        elementos_[j / 2] = elementos_[j];
        j *= 2;
    }

    elementos_[j / 2] = v;
}

#endif