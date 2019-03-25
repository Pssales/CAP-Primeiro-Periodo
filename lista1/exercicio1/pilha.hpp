/*Projete e implemente uma estrutura de dados do tipo pilha que
permita empilhar e desempilhar números inteiros. Esta estrutura deverá fornecer as
seguintes operações:
• push(v): Empilha um número inteiro.
• pop(): Desempilha o elemento no topo da pilha.
• top(): Retorna o valor do elemento no topo da pilha.
• empty(): Retorna verdadeiro se a pilha estiver vazia, caso contrário, retorna falso.
Além das operações acima, os clientes da pilha poderão criar objetos com uma determinada capacidade inicial de armazenamento (ex: 4 elementos). No entanto, durante as
operações de empilhamento (push), caso haja a necessidade de alocação de mais memória,
a implementação deverá cuidar desses detalhes
*/
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