#include <iostream>

#include "no.cpp"
class Lista
{
private:
    No *front_ = NULL;
    No *back_ = NULL;

public:

    int front(){
        if (front_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
            return -1;
        }
        return front_->value_;
    } 

    int back(){
        if (back_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
            return -1;
        }
        return back_->value_;
    }

    void push_front(int value)
    {
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

    void push_back(int value)
    {
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

    void pop_front(){
        if (front_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
        }else
        {
            front_ = front_->next_;
        }
    }

    void pop_back(){
        if (back_ == NULL) {
            std::cout << "Lista Vazia!!!" << std::endl;
        }else
        {
            back_ = back_->previous_;
            back_->next_ = NULL;
        }
    }

    void exibeLista(){
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
};
