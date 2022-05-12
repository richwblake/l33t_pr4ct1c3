#include "bst.h"
#include <iostream>

int main () {
    BST tree (3);
    int root = tree.getRoot();
    std::cout << root << std::endl;
}
