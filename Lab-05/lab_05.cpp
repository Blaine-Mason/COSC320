#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <utility>

#include "int.h"
#include "d_except.h"
#include "d_stree.h"

/*
* File Name: Lab_05.cpp
* Author: Blaine Mason
* Assignment: Lab-05
*/

int main(){
    //Seed for the random value
    srand(time(0));

    //Tree of integers
    stree<integer> int_Tree;

    //Perform 10,000 iterations
    for(int i = 0; i < 10000; i++){
        
        //Create a random number from 0-6
        int rndNum = rand() % 7;

        //Assign the node to point to the node of the random number(if found)
        stnode<integer> *searchN = int_Tree.findNode(rndNum);
        //If searchN is NULL, the random value DNE in the tree
        if(searchN == NULL){
            //So insert into the tree
            int_Tree.insert(rndNum);
        }else{
            //Increment the count since the element exists
            searchN->nodeValue.incCount();
        }
    }

    stnode<integer> *temp;
    std::cout << "Run: " << std::endl;

    //Output the values in the tree
    std::cout << "Values in the tree: " << std::endl;
    for(int i = 0; i < 7; i++){
        temp = int_Tree.findNode(i);
        std::cout << temp->nodeValue << std::endl;
    }
    std::cout << std::endl;

    //Output the tree itself
    std::cout << "The Tree:" << std::endl;
    int_Tree.displayTree(4);
}
