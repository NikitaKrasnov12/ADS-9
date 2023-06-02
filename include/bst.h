// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>

class BST {
 private:
    struct Node {
     Node* left;
     Node* right;
     int count;
     T value;
    };
    Node* root;
    Node* add_Node(Node* root, T value) {
     if (!root) {
      root = new Node;
      root->value = value;
      root->count = 1;
      root->right = nullptr;
      root->left = nullptr;
     } else {
      if (root->left || root->right) {
       if (root->value > value) {
        root->left = add_Node(root->left, value);
       } else if (root->value < value) {
        root->right = add_Node(root->right, value);
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
        int lef = depth_Tree(root->left);
        int rig = depth_Tree(root->right);
        if (lef == 0 && rig == 0) {
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
      } else if (value < root->value && root->left != nullptr) {
        return search_Node(root->left, value);
      } else if (value > root->value && root->right != nullptr) {
        return search_Node(root->right, value);
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
