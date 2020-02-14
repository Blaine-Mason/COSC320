#include <iostream> 
#include "countOneChild.h"
#include "d_tnode1.h"

int main(){ 
  tnode<char> *root, *b, *c, *d, *e, *f, *g;
  g = new tnode<char> ('G');
  e = new tnode<char> ('E', (tnode<char> *)NULL, g);
  f = new tnode<char> ('F');
  c = new tnode<char> ('C', e, f);
  d = new tnode<char> ('D');
  b = new tnode<char> ('B', d, (tnode<char> *)NULL);
  root = new tnode<char> ('A', b, c);

  int OCCount = 0;
  countOneChild(root, OCCount); 
  std::cout << "One Child Count: " << OCCount << std::endl;
  displayTree(root, 7);
} 
