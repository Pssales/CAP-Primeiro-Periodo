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

// C++ Standard Library
#include <iostream>
#include <string>
#include <locale.h>
// MyCode
#include "pilha.hpp"
 
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese_Brasil.1252");
    int tamanho;
	std::cout << "Qual o tamanho da pilha?" << std::endl;
    std::cin >> tamanho ;
    Pilha p(tamanho);

    int option;
    do
    {
        std::cout << "------------------" << std::endl;
        std::cout << "Escolha uma das alternativas:" << std::endl;
        std::cout << "1 - Empilhar" << std::endl;
        std::cout << "2 - Remover topo" << std::endl;
        std::cout << "3 - Exibir topo" << std::endl;
        std::cout << "4 - Verificar se esta vazia" << std::endl;
        std::cout << "0 - Encerrar o programa" << std::endl;
        std::cin >> option ;

        switch (option){
            case 1:
                int value;
                std::cout << "Informe o valor" << std::endl;
                std::cin >> value ;
                p.push(value);
            break;
            case 2:
                p.pop();
            break;
            case 3:
                std::cout << p.top() << std::endl;
            break;
            case 4:
                std::cout << p.empty() << std::endl;
            break;
        }
        
    } while (option != 0);
   
    return 0;

}