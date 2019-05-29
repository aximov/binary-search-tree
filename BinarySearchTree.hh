//
// Created by Akimoto Daichi on 2019-05-22.
//

#ifndef BINARY_SEARCH_TREE_BINARYSEARCHTREE_HH
#define BINARY_SEARCH_TREE_BINARYSEARCHTREE_HH

#include <iostream>


struct Node {
  int key;
  Node* left;
  Node* right;
  Node* parent;
};

class BinarySearchTree {
private:
  Node* _root;

public:
  BinarySearchTree() {
    _root = nullptr;
  }

  ~BinarySearchTree(){
    releaseMemory(_root);
  }

  void insert(int number){
    auto __node_new = new Node {number, nullptr, nullptr, nullptr};
    if (_root != nullptr) {
      treeInsert(__node_new);
    } else {
      _root = __node_new;
    }
  }

  bool find(int number){
    return iterativeTreeSearch(_root, number) != nullptr;
  }

  void Print(void){
    inorderTreeWalk(_root);
  }

  void deleteNode(int number){
    auto itr = iterativeTreeSearch(_root, number);
    if (itr) treeDelete(itr);
    else std::cout << number << " is missing, could not delete" << std::endl;
  }


private:
  void inorderTreeWalk(Node* node){
    if (node != nullptr) {
      inorderTreeWalk(node->left);
      std::cout << node->key << std::endl;
      inorderTreeWalk(node->right);
    }
  }

  Node* treeSearch(Node* node, int key) {
    if (node == nullptr || key == node->key) {
      return node;
    }
    if (key < node->key) return treeSearch(node->left, key);
    else return treeSearch(node->right, key);
  }

  Node* iterativeTreeSearch(Node* node, int key) {
    while (node != nullptr && key != node->key) {
      if (key < node->key) node = node->left;
      else node = node->right;
    }
    return node;
  }

  void treeInsert(Node* node_new) {
    Node* node_trailing = nullptr;
    Node* node = _root;

    while (node != nullptr) {
      node_trailing = node;
      if (node_new->key < node->key) node = node->left;
      else node = node->right;
    }

    node_new->parent = node_trailing;

    if (node_trailing == nullptr) _root = node_new;
    else if (node_new->key < node_trailing->key) node_trailing->left = node_new;
    else node_trailing->right = node_new;
  }

  void transplant(Node* node_a, Node* node_b) {
    if (node_a->parent == nullptr) _root = node_b;
    else if (node_a == node_a->parent->left) node_a->parent->left = node_b;
    else node_a->parent->right = node_b;

    if (node_b != nullptr) node_b->parent = node_a->parent;
  }

  Node* treeMinimum(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
  }

  void treeDelete(Node* node) {
    if (node->left == nullptr) transplant(node, node->right);
    else if (node->right == nullptr) transplant(node, node->left);
    else {
      Node* node_next = treeMinimum(node->right);

      if (node_next->parent != node) {
        transplant(node_next, node_next->right);
        node_next->right = node->right;
        node_next->right->parent = node_next;
      }

      transplant(node, node_next);
      node_next->left = node->left;
      node_next->left->parent = node_next;
    }
  }

  void releaseMemory(Node *node){
    if (node != nullptr) {
      releaseMemory(node->left);
      releaseMemory(node->right);
      delete node;
    }
  }
};


#endif //BINARY_SEARCH_TREE_BINARYSEARCHTREE_HH
