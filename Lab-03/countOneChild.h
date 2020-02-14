#ifndef COUNTONECHILD
#define COUNTONECHILD

#include "d_tnode.h"

template <typename T>
void countOneChild(tnode<T> *t, int &OneChild){
  if(t != NULL){
    if((t->left != NULL || t->right != NULL) && !(t->left != NULL && t->right != NULL)){
      OneChild++;
    }
    countOneChild(t->left, OneChild);
    countOneChild(t->right, OneChild);
  }
};

#endif    
