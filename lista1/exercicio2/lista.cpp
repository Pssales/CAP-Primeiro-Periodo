#include <iostream>

#include "lista.hpp"

    Lista::Lista()
    {
        front_ = NULL;
        back_ = NULL;
    }

    int Lista::front(){
        if (front_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
            return -1;
        }
        return front_->value_;
    } 

    int Lista::back(){
        if (back_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
            return -1;
        }
        return back_->value_;
    }

    void Lista::push_front()
    {
        int value;
        std::cout << "Informe o número" << std::endl;
        std::cin >> value ;

        No *newElement;

        newElement = new No;

        newElement->value_ = value;

        newElement->next_ = NULL;
        newElement->previous_ = NULL;

        if(front_ == NULL)
        {
            front_ = newElement;
            back_ = newElement;
        }
        else
        {
            front_->previous_ = newElement;
            newElement->next_ = front_;
            front_ = newElement;    
        }

    }

    void Lista::push_back()
    {

        int value;
        std::cout << "Informe o número" << std::endl;
        std::cin >> value ;
        
        No *newElement;

        newElement = new No;

        newElement->value_ = value;

        newElement->next_ = NULL;
        newElement->previous_ = NULL;

        if(front_ == NULL)
        {
            front_ = newElement;
            back_ = newElement;   
        }
        else
        {
            back_->next_ = newElement;
            newElement->previous_ = back_;
            back_ = newElement;
        }
    }

    void Lista::pop_front(){
        if (front_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
        }else
        {
            front_ = front_->next_;
        }
    }

    void Lista::pop_back(){
        if (back_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
        }else
        {
            back_ = back_->previous_;
            back_->next_ = NULL;
        }
    }

    void Lista::exibeLista(){
    No *aux;
    if(front_ == NULL){
        printf("Lista Vazia");
    }
    aux = front_;
    while(aux != NULL)
    {
        printf("Info = %dn", aux->value_);
        aux = aux->next_;
    }
    printf("----------------fim-----------");
}

