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
            };

            // Contructor and destructor
            Fila();
            ~Fila();

            // Basic functions
            void insert(const Template& val);
            void remove();
            Template front();
            Template back();

            void print();
            void clear(Node * n);
    
            Node* begin_;
            Node* end_;

            private:
                Fila(Fila&);
                Fila& operator=(Fila&);
    };
    
    template<class Template> 
    Fila<Template>::Fila()
    {
        begin_ = NULL;
        end_ =  NULL;
    }
    
    template<class Template>
    Fila<Template>::~Fila()
    {
        clear(begin_);
    }

    template<class Template> void
    Fila<Template>::insert(const Template& val)
    {
        Node * newNode = new Node();
        newNode->next_ = NULL;
        newNode->val_ = val;
        if(begin_ == NULL){
            begin_ = newNode;
            end_ = newNode;
        }else{
            end_->next_ = newNode;
            end_ = newNode;
        }
    }

    template<class Template> void
    Fila<Template>::remove()
    {
        begin_ = begin_->next_; 
    }

    template<class Template> Template
    Fila<Template>::front()
    {
        return begin_->val_;
    }

    template<class Temlate> Template
    Fila<Template>::back()
    {
        return end_->val_;
    }

    template<class Temlate> Template
    Fila<Template>::print()
    {
        if(begin_ != NULL){
            std::cout << begin_->val_;
            Node temp = begin_;
            while (temp->next_ != null)
            {
                std::cout << temp->val_;
                temp = temp->next_;
            }
            
        }

    }

    template<class Template> void
    Fila<Template>::clear(Node * n) {
        if (n->next_ != NULL) {
            clear(n->next_);
        }
        delete n;
    }

#endif