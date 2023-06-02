// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> bst;
    std::ifstream file(filename);
    std::string slovo;
    while (!file.eof()) {
        char c = file.get();
        if (c >= 65 && c <= 90) {
            c += 32;
            slovo = slovo + c;
            continue;
        }
        if (c >= 97 && c <= 122) {
            slovo = slovo + c;
        } else {
            if (!slovo.empty()) {
                bst.add(slovo);
            }
            slovo.clear();
        }
    }
    bst.add(slovo);
    file.close();
    return bst;
}
