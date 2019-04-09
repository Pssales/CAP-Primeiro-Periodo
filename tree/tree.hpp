#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <iostream>

template <class Template>
    class Tree{
        public:
            struct Node{
                Node* left;
                Node* right;
                Template data;
            };

            //Constructor
            Tree();
            //Destructor
            ~Tree();

            //Basic Functions
            Node* getRoot();
            int level(Node* node);
            
            void insert(const Template& value);
            node * find(const Template& value, node * n) const;
            void remove(node * position);

            //Print Functions
            void print(node * n); 
            void preOrder(node * n);
            void inOrder(node * n);
            void posOrder(node * n);

        //Block constructor with object and assignment
        private:
            Tree(Tree&);
            Tree& operator=(Tree&);

        private:
            node * root;

    };

    

#endif