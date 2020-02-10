#ifndef BINSEARCH_H
#define BINSEARCH_H
#include <iostream>
#include "deSelsort.h"

/*
 * File Name: binSearch.h
 * Method: binSearch
 * Return Type: integer
 * In: SORTED Array of integers "arr", size of "arr", target value, 
 *     compare which is passed by reference to count comparisons
 *     for a failed search.
 * Out: The index of the item in the array or -1 if the item
 *      is not found.
*/
int binSearch(int arr[], int size, int target, int& compare){
  //left -> starts at the first index
  //right -> holds the values of the right most, which is size minus 1
  //         because arrays count from 0
	int left = 0, right = size -1;
  
  //While left is less than or equal to the right, basically while 
  //while you can still cut it in half.
	while (left <= right){
    //middle -> holds the value of the middle, which is done by,
    //          integer division to truncate to a value 
    //          i.e. 5/2 != 2.5, but actually 2.
		int middle = (left + right)/2;

    //if the value we are looking for is smaller than the 
    //value held by the middle
		if(target < arr[middle]){
      //change the right most bound to be to the left of the middle(SORTED)
			right = middle - 1;
		}else if(target > arr[middle]){ //If the value is larger than that held by the middle
      //change the left most bound to be to the right of the middle(SORTED) 
			left = middle + 1;
		}else{
      //the index of the value if it is found
			return middle;
		}
    //one comparison will occur every iteration of the while loop, so increment 
    //compare each time the while finishes an iteration
		compare++;
	}
  //if this return is reached then the value DNE in the array.
	return -1;
};
#endif
 
