#ifndef __LIST_EXE04__
#define __LIST_EXE04__

#include <iostream>

template<class Template>
class Tree {
    public:
        struct node {
            node * left;
            node * right;
            node * parent;
            Template data;
        };

        Tree();
        ~Tree();

        node * getRoot();
        int level(node * n);
        const Template& retrieve(node * n) const;
        void print(node * n);

        void insert(const Template& value);
        node * find(const Template& value, node * n) const;
        void remove(node * position);

        void preOrder(node * n);
        void inOrder(node * n);
        void posOrder(node * n);

        int height(node * n);

        void clear(node * n);
    private:
        Tree(Tree&);
        Tree& operator=(Tree&);
    private:
        node * root;
};

//Constructor and Destructor
template<class Template>
Tree<Template>::Tree () {
    root = NULL;
}

template<class Template>
Tree<Template>::~Tree () {
    clear(root);
}

//Methods

template<class Template> typename Tree<Template>::node *
Tree<Template>::getRoot() {
    return root;
}

template<class Template> int
Tree<Template>::level(node * n){
    int l = 1;
    while (n->parent != NULL) {
        l ++;
        n = n->parent;
    }
    return l; 
}

template<class Template> const Template&
Tree<Template>::retrieve(node * n) const {
    return n->data;
}

template<class Template> void
Tree<Template>::print(node * n) {
    if (n->right != NULL) {
        print (n->right);
    }
    for (int i = 0; i < level(n); i++) {
        std::cout << "    ";
    }
    std::cout << n->data << std::endl;
    if (n->left != NULL) {
        print (n->left);
    }
}

template<class Template> void
Tree<Template>::insert(const Template& value) {
    node * n = root;
    node * parent = NULL;
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
    neo->left = NULL;
    neo->right = NULL;
    neo->parent = parent;
    if (parent == NULL) {
        root = neo;
    }else if(value < parent->data) {
        parent->left = neo;
    }else{
        parent->right = neo;
    }
}

template<class Template> typename Tree<Template>::node *
Tree<Template>::find(const Template& value, node * n) const {
    if (n == NULL) {
        return NULL;
    }
    if (n->data == value) {
        return n;
    }
    return (value < n->data) ? find(value, n->left) : find(value, n->right);
}

template<class Template> void
Tree<Template>::remove(node * position) {
    //First case: Leaf node
    if (position->left == NULL && position->right == NULL) {
        if (position->parent != NULL) {
            if (position->parent->left = position) {
                position->parent->left = NULL;
            }else{
                position->parent->right = NULL;
            }
        }
        delete position;
        return;
    }

    //Second case: One child (An ugly mess of ifs and elses...)
    if (position->left != NULL && position->right == NULL) {
        //std::cout << "Second Case: Left" << std::endl;
        if (position->parent != NULL) {
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
            position->left->parent = NULL;
            root = position->left;
        }
        //std::cout << "Deleting Position" << std::endl;
        delete position;
        return;
    }
    if (position->right != NULL && position->left == NULL) {
        //std::cout << "Second Case: Right" << std::endl;
        if (position->parent != NULL) {
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
            position->right->parent = NULL;
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
    leaf->parent->right = NULL;
    delete leaf;
}

template<class Template> void
Tree<Template>::preOrder(node * n) {
    std::cout << n->data << " ";
    if (n->left != NULL) {
        preOrder (n->left);
    }
    if (n->right != NULL) {
        preOrder (n->right);
    }
}

template<class Template> void
Tree<Template>::inOrder(node * n) {
    if (n->left != NULL) {
        inOrder (n->left);
    }
    std::cout << n->data << " ";
    if (n->right != NULL) {
        inOrder (n->right);
    }
}

template<class Template> void
Tree<Template>::posOrder(node * n){
    if (n->left != NULL) {
        posOrder (n->left);
    }
    if (n->right != NULL) {
        posOrder (n->right);
    }
    std::cout << n->data << " ";
}

template<class Template> int
Tree<Template>::height(node * n) {
    int h = 0;
    if (n->left != NULL) {
        h = height (n->left);
    }
    if (n->right != NULL) {
        h = height (n->right);
    }
    int l = level(n);
    if (l > h) {
        h = l;
    }
    return h;
}

template<class Template> void
Tree<Template>::clear(node * n) {
    if (n->right != NULL) {
        clear (n->right);
    }
    if (n->left != NULL) {
        clear (n->left);
    }
    delete n;
}

#endif