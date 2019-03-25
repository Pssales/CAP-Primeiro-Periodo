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

// MyCode
#include "pilha.hpp"
 
// C++ Standard Library
#include <iostream>
 
int main(int argc, char *argv[])
{
	 
    Pilha p;
    std::cout << "vazia:" << p.empty() << std::endl;
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    std::cout << "topo:" << p.top() << std::endl;
    p.pop();
    std::cout << "topo:" << p.top() << std::endl;
    std::cout << "vazia:" << p.empty() << std::endl;
    
    return 0;

}