#ifndef COUNTONECHILD
#define COUNTONECHILD

#include "d_tnode.h"

template <typename T>
void countOneChild(tnode<T> *t, int &OneChild){
  if(t != NULL){
    //If there exists a node in the left or right but not both
    //(Exclusive Or, XOR)
    if((t->left != NULL || t->right != NULL) && !(t->left != NULL && t->right != NULL)){
       //count one child because it exists
       OneChild++;
    }
    //traverse left
    countOneChild(t->left, OneChild);
    //traverse right
    countOneChild(t->right, OneChild);
  }
};

#endif    
