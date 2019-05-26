#ifndef __FILA__HPP__
#define __FILA__HPP__

#include <iostream>

template <class Template>

    class Fila
    {
        public:

            struct Node{
                Node* next_;
                Template val_;
            }

            // Contructor and destructor
            Fila();
            ~Fila();

            // Basic functions
            void insert(const Template& val);
            void remove();
            Template front();
            Template back();

        
    
        private:
            Node* begin_;
            Node* end_;
    };
    
    template<class Template> 
    Fila<Template>::Fila()
    {
        begin_ = NULL;
        end_ =  NULL;
    }
    
    template<class Template>
    Fila<Template>::~Fila()
    {}

    template<class Template> void
    Fila<Template>::insert(const Template& val)
    {
        Node * newNode = new Node();
        newNode->next_ = NULL;
        newNode->val_ = val;
        if(begin == NULL){
            ge
        }
    }

    template<class Template> void
    Fila<Template>::remove()
    {

    }

    template<class Template> Template
    Fila<Template>::front()
    {

    }

    template<class Temlate> Template
    Fila<Template>::back()
    {

    }


#endif