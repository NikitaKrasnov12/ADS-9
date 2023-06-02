// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>

class BST {
 private:
    struct Node {
     Node* left_Tree;
     Node* right_Tree;
     int count;
     T value;
    };
    Node* root;
    Node* add_Node(Node* root, T value) {
     if (!root) {
      root = new Node;
      root->value = value;
      root->count = 1;
      root->right_Tree = nullptr;
      root->left_Tree = nullptr;
     } else {
      if (root->left_Tree || root->right_Tree) {
       if (root->value > value) {
        root->left_Tree = add_Node(root->left_Tree, value);
       } else if (root->value < value) {
        root->right_Tree = add_Node(root->right_Tree, value);
       } else {
        ++root->count;
       }
      }
     }
     return root;
    }
    int depth_Tree(Node* root) {
        if (root == nullptr) {
         return 0;
        }
        int lef = heightTree(root->left_Tree);
        int rig = heightTree(root->right_Tree);
        if(lef == 0 && rig == 0) {
         return 0;
        }
        if (lef > rig) {
         return lef + 1;
        } else {
         return rig + 1;
        }
    }
    int search_Node(Node* root, T value) {
      if (root->value == value) {
        return root->count;
      } else if (value < root->value && root->left_Tree != nullptr) {
        return search_Node(root->left_Tree, value);
      } else if (value > root->value && root->right_Tree != nullptr) {
        return search_Node(root->right_Tree, value);
      }
      return 0;
    }

 public:
    BST():root(nullptr) {}
    void add(T value) {
        root = add_Node(root, value);
    }
    int search(T value) {
        return  search_Node(root, value);
    }
    int depth() {
        return depth_Tree(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
