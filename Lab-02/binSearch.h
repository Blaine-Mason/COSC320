#ifndef BINSEARCH_H
#define BINSEARCH_H
#include <iostream>
#include "deSelsort.h"

int binSearch(int arr[], int size, int target, int& compare){
	int left = 0, right = size -1;
	while (left <= right){
		int middle = (left + right)/2;
		if(target < arr[middle]){
			right = middle - 1;
		}else if(target > arr[middle]){
			left = middle + 1;
		}else{
			return middle;
		}
		compare++;
	}
	return -1;
};
#endif
 
