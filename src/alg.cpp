// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> bst;
    std::ifstream file(filename);
    for (char& c : file) {
        // Convert uppercase letters to lowercase
        if (c >= 65 && c <= 90) {
            c += 32;
        }
        if (c >= 97 && c <= 122) {
            bst.add(std::string(1, c));
        }
    }
    file.close();
    return bst;
}
