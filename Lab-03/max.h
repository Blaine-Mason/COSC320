#ifndef MAX
#define MAX

#include "d_tnode.h"
template <typename T>
int maxValue(tnode<T> *t){
  int maxV = 0;
  if(t != NULL){
    maxV = t->nodeValue;
    int leftV = maxValue(t->left);
    int rightV = maxValue(t->right);
    if(leftV > maxV){
      maxV = leftV;
    }
    if(rightV > maxV){
      maxV = rightV;
    }
  }
  return maxV;
};

#endif
