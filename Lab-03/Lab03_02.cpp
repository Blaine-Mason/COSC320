#include <iostream>
#include "d_tnode1.h"
#include "max.h"



int main(){
  
  tnode<int> *root, *a, *b, *c, *d, *e;
  //construct the Tree 2
  a = new tnode<int>(5);
  b = new tnode<int>(48);
  c = new tnode<int>(12);
  d = new tnode<int>(40, a, (tnode<int> *)NULL);
  e = new tnode<int>(15, b, c);
  root = new tnode<int>(35, d, e);
  
  //max -> stores the max value
  int max = maxValue(root);
  std::cout << "Max Value in Tree is: " << max << std::endl;
  //Displays the tree to verify it was built correctly
  displayTree(root, 6);
}
