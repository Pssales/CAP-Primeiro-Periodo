#include <iostream>
#include "lista.hpp"
#include <stdio.h>
int main(void)
{
    Lista lista;

    int option;
    do
    {
        std::cout << "------------------" << std::endl;
        std::cout << "Escolha uma das opções:" << std::endl;
        std::cout << "1 - Retornar o primeiro elemento" << std::endl;
        std::cout << "2 - Retorna o último elemento " << std::endl;
        std::cout << "3 - Inserir Valor no Início" << std::endl;
        std::cout << "4 - Inserir Valor no Final" << std::endl;
        std::cout << "5 - Remover o primeiro elemento " << std::endl;
        std::cout << "6 - Remover o último elemento" << std::endl;
        std::cout << "0 - Encerar o programa" << std::endl;
        std::cin >> option ;

        switch (option){
            case '1':
                std::cout << lista.front() <<"\n\n";
            break;
            case '2':
                std::cout << lista.back() <<"\n\n";
            break;
            case '3':
                lista.pop_front();
            break;
            case '4':
                lista.pop_back();
            break;
            case '5':
                lista.pop_front();
            break;
            case '6':
                lista.pop_back();
            break;
        }
        
    } while (option != 0);

}