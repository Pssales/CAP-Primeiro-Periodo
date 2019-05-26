#include "tree.hpp"
#include <iostream>

int main () {

    Tree<int> tree;
    tree.insert(25);
    tree.insert(12);
    tree.insert(8);
    tree.insert(15);
    tree.insert(35);
    tree.insert(27);
    tree.insert(42);
    tree.insert(3);
    tree.insert(1);
    tree.insert(57);
    tree.insert(9);
    tree.insert(43);
    tree.insert(10);
    tree.insert(7);
    tree.insert(13);
    tree.insert(16);
    tree.insert(19);
    tree.print(tree.getRoot());
    
    std::cout << "-------------------------------------" << std::endl;

    std::cout << "Tree height:" << tree.height(tree.getRoot()) << std::endl;
    std::cout << "-------------------------------------" << std::endl;


    return 0;
}