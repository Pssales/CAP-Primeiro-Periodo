#include <iostream>
#include "lista.hpp"

int main(void)
{
    Lista lista;
    std::cout << "Front " <<  lista.front() << std::endl;

    lista.push_front(1);
    lista.push_front(2);
    lista.push_back(3);
    lista.push_back(4);
    lista.exibeLista();
    std::cout << "------------------" << std::endl;
    lista.pop_front();
    lista.exibeLista(); 
    std::cout << "------------------" << std::endl;

    lista.pop_back();
    lista.exibeLista();   
    std::cout << "------------------" << std::endl;


    std::cout << "Front " <<  lista.front() << std::endl;
    std::cout << "Back  " <<  lista.back() << std::endl;
}