#ifndef __PILHA_HPP__
#define __PILHA_HPP__

class Pilha {

    public:
        Pilha();
        ~Pilha();

        //Methods
        void push(int value);
        void pop();

        int top();
        bool empty();

    private:
        int * vet_;
        int max_tam_;
        int topo_;

};

#endif