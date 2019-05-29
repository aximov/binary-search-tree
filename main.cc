//
// Created by Akimoto Daichi on 2019-05-22.
//

#include <iostream>
#include "BinarySearchTree.hh"

int main() {
  auto tree = new BinarySearchTree();

  for (int i = 0; i < 10; ++i) {
    tree->insert(i);
  }

  tree->Print(); // 0 - 9

  bool flg = true;
  for (int i = 0; i < 10; ++i) {
    if(!tree->find(i)) flg = false;
  }

  if(flg) std::cout << "Yes" << std::endl; // "Yes"
  else std::cout << "No" << std::endl;

  for (int i = 1; i < 11; ++i) {
    tree->deleteNode(i); // "10 is missing, could not delete"
  }

  tree->Print(); // 0

  tree->insert(-100);
  tree->insert(100);

  tree->Print(); // -100, 0, 100

  delete tree;
  return 0;
}