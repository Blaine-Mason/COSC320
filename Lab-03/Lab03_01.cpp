#include <iostream> 
#include "countOneChild.h"
#include "d_tnode1.h"
  
/*
* File Name: Lab_03_01.cpp
* Author: Blaine Mason
* Assignment: Lab-03
*/
int main(){
  //Building the Tree 1 to test the countOneChild function
  tnode<char> *root, *b, *c, *d, *e, *f, *g;
  g = new tnode<char> ('G');
  e = new tnode<char> ('E', (tnode<char> *)NULL, g);
  f = new tnode<char> ('F');
  c = new tnode<char> ('C', e, f);
  d = new tnode<char> ('D');
  b = new tnode<char> ('B', d, (tnode<char> *)NULL);
  root = new tnode<char> ('A', b, c);
  
  //Variables to test the functionality
  int OCCount = 0;
  countOneChild(root, OCCount); 
  std::cout << "One Child Count: " << OCCount << std::endl;
  //Display Tree to show that it was constructed
  //correctly
  displayTree(root, 7);
} 
