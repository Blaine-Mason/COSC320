#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <utility>

#include "int.h"
#include "d_except.h"
#include "d_stree.h"
#include "d_random.h"

int main(){
    srand(time(0));

    stree<integer> int_Tree;

    for(int i = 0; i < 10000; i++){
        

        int rndNum = rand() % 7;

        //std::cout << rndNum << std::endl;

        stnode<integer> *searchN = int_Tree.findNode(rndNum);

        if(searchN == NULL){
            int_Tree.insert(rndNum);
        }else{
            searchN->nodeValue.incCount();
        }
    }

    stnode<integer> *temp;
    std::cout << "Run: " << std::endl;

    std::cout << "Values in the tree: " << std::endl;
    for(int i = 0; i < 7; i++){
        temp = int_Tree.findNode(i);
        std::cout << temp->nodeValue << std::endl;
    }
    std::cout << std::endl;

    
    std::cout << "The Tree:" << std::endl;
    int_Tree.displayTree(5);
}
