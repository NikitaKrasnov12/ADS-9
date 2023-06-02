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
      if (root->left_Tree != nullptr || root->right_Tree != nullptr) {
        if (value < root->value && root->left_Tree != nullptr) {
           return search(root->left_Tree, value)
        }
        if (val > root->value && root->right_Tree != nullptr) {
          return search_Node(root->right_Tree, value)
        }
      } else {
          if (root->value > value) {
            root->left_Tree = add_Node(root->left_Tree, value);
          } else if (root->value < value) {
            root->right_Tree = add_Node(root->right_Tree, value);
          } else {
            ++root->count;
          }
        }
        return root;
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
    int depth_Tree(Node* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int l = depth_Tree(root->left_Tree);
            int r = depth_Tree(root->right_Tree);
            return 1 + (l >= r ? l : r);
        }
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
