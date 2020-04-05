#include <iostream>
#include "d_pqueue.h"
#include "preqrec.h"
#include <stdlib.h>
#include <cstdlib> //for random numbers
#include <string>


int main(){
    
    srand(time(0));
    
    miniPQ<procReqRec> mpq;
    
    std::string letters[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    
    procReqRec ar[10];
    
    for(int i = 0; i < 10; i++){
        std::string nm = "Priority " + letters[i];
        ar[i].setName(nm);
        ar[i].setPriority(rand() % 40);
    }
    
    for(int j = 0; j < 10; j++){
        std::cout << mpq.top();
        mpq.pop();
    }

    return 0;
    
}