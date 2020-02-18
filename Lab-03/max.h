#ifndef MAX
#define MAX

#include "d_tnode.h"
template <typename T>
int maxValue(tnode<T> *t){
  //maxV -> holds the value that will eventually 
  //        contain the max value
  int maxV = 0;
  if(t != NULL){
    //Assign maxV to the valaue of the root by default
    maxV = t->nodeValue;
    //traverse left
    int leftV = maxValue(t->left);
    //traverse right
    int rightV = maxValue(t->right);
    
    //if either the left or right is bigger, 
    //assign it to maxV respectively
    if(leftV > maxV){
      maxV = leftV;
    }
    if(rightV > maxV){
      maxV = rightV;
    }
  }
  //Return the max value
  return maxV;
};

#endif
