#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <iostream>

template <class Template>
    class Tree{
        public:
            struct Node{
                Node* left;
                Node* right;
                Node* parent;
                Template data;
            };

            //Constructor
            Tree();
            //Destructor
            ~Tree();

            //Basic Functions
            int level(Node* node); 
            void insert(const Template& value);
            void remove(Node * position);

            //Print Functions
            void print(Node * n); 
            void preOrder(Node * n);
            void inOrder(Node * n);
            void posOrder(Node * n);

        //Block constructor with object and assignment
        private:
            Tree(Tree&);
            Tree& operator=(Tree&);

        private:
            node * root;

    };

    //Constructor
    template<class Template>
    Tree<Template>::Tree(){
        root = NULL;
    }

    //Destructor
    template<class Template>
    Tree<Template>::~Tree(){
       delete(root);
    }


    //Basic Functions
    template<class Template> int
    Tree<Template>::level(Node * n){
        int l = 1;
        while (n->parent != nullptr) {
            l ++;
            n = n->parent;
        }
        return l; 
    }    

    template<class Template> void
    Tree<Template>::insert(const Template& value) {
        node * n = root;
        node * parent = nullptr;
        while (n) {
            if (n->data == value) {
                std::cout << "Duplicated value is not allowed!" << std::endl;
                return;
            }
            parent = n;
            n = (value < n->data) ? n->left : n->right;
        }
        node * neo = new node();
        neo->data = value;
        neo->left = nullptr;
        neo->right = nullptr;
        neo->parent = parent;
        if (parent == nullptr) {
            root = neo;
        }else if(value < parent->data) {
            parent->left = neo;
        }else{
            parent->right = neo;
        }
    }

    template<class Template> void
    Tree<Template>::remove(Node * position) {
        //First case: Leaf node
        if (position->left == nullptr && position->right == nullptr) {
            if (position->parent != nullptr) {
                if (position->parent->left = position) {
                    position->parent->left = nullptr;
                }else{
                    position->parent->right = nullptr;
                }
            }
            delete position;
            return;
        }

        //Second case: One child (An ugly mess of ifs and elses...)
        if (position->left != nullptr && position->right == nullptr) {
            //std::cout << "Second Case: Left" << std::endl;
            if (position->parent != nullptr) {
                //std::cout << "There is a parent" << std::endl;
                if (position->parent->left == position) {
                    //std::cout << "I'm a left child" << std::endl;
                    position->parent->left = position->left;
                }else{
                    //std::cout << "I'm a right child" << std::endl;
                    position->parent->right = position->left;
                }
                position->left->parent = position->parent;
            }else{
                //std::cout << "There is no parent" << std::endl;
                position->left->parent = nullptr;
                root = position->left;
            }
            //std::cout << "Deleting Position" << std::endl;
            delete position;
            return;
        }
        if (position->right != nullptr && position->left == nullptr) {
            //std::cout << "Second Case: Right" << std::endl;
            if (position->parent != nullptr) {
                //std::cout << "There is a parent" << std::endl;
                if (position->parent->left == position) {
                    //std::cout << "I'm a left child" << std::endl;
                    position->parent->left = position->right;
                }else{
                    //std::cout << "I'm a right child" << std::endl;
                    position->parent->right = position->right;
                }
                position->right->parent = position->parent;
            }else{
                //std::cout << "There is no parent" << std::endl;
                position->right->parent = nullptr;
                root = position->right;
            }
            //std::cout << "Deleting Position" << std::endl;
            delete position;
            return;
        }
        
        //Third case: Two children
        node * temp = position->left;
        node * leaf;
        while (temp) {
            leaf = temp;
            temp = temp->right;
        }
        position->data = leaf->data;
        leaf->parent->right = nullptr;
        delete leaf;
    }
    //Print functions

    template<class Template> void
    Tree<Template>::print(Node * n) {
        if (n->right != nullptr) {
            print (n->right);
        }
        for (int i = 0; i < level(n); i++) {
            std::cout << "    ";
        }
        std::cout << n->data << std::endl;
        if (n->left != nullptr) {
            print (n->left);
        }
    }

    template<class Template> void
    Tree<Template>::preOrder(Node * n) {
        std::cout << n->data << " ";
        if (n->left != nullptr) {
            preOrder (n->left);
        }
        if (n->right != nullptr) {
            preOrder (n->right);
        }
    }

    template<class Template> void
    Tree<Template>::inOrder(Node * n) {
        if (n->left != nullptr) {
            inOrder (n->left);
        }
        std::cout << n->data << " ";
        if (n->right != nullptr) {
            inOrder (n->right);
        }
    }

    template<class Template> void
    Tree<Template>::posOrder(Node * n){
        if (n->left != nullptr) {
            posOrder (n->left);
        }
        if (n->right != nullptr) {
            posOrder (n->right);
        }
        std::cout << n->data << " ";
    }

#endif