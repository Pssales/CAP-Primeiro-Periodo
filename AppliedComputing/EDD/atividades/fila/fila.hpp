#ifndef __FILA__HPP__
#define __FILA__HPP__

#include <iostream>

template <class Template>

    class Fila
    {
        public:

            struct Node{
                Node* next;
                Template val;
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
            Node* begin;
            Node* end;
    };
    
    template<class Template> 
    Fila<Template>::Fila()
    {
        begin = NULL;
        end = NULL
    }
    
    template<class Template>
    Fila<Template>::~Fila()
    {}

    template<class Template> void
    Fila<Template>::insert(const Template& val)
    {

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