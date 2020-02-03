#ifndef DESELSORT_H
#define DESELSORT_H
#include <iostream>

/*
 * File Name: deSelsort.h
 * Method: deSelsort
 * Return Type: void
 * In: array of integers "arr", size of "arr", ascending boolean to 
 *		 enable ascending or descending order.
 * Out: "arr" is sorted in ascending or descending order respectively
*/
void deSelsort(int arr[], int n, bool ascending){
	//minIndex -> holds the index of the minimun value
	//maxindex -> holds the index of the maximum value
	//temp -> holds a temp value for swapping
	//leftMost -> holds the index of the left most position
	//swapCount -> holds the count of swaps in the loop, for demonstration
	int minIndex, maxIndex, temp, leftMost = 0, swapCount = 0;


	//while the ith index(0, 1, 2...) is no larger than the nth-ith-1(n-2, n-1, n)
	while(i <= n-i-1){
		//rightMost -> holds the index of the right most position
		int rightMost = n-i-1;

		//left the min and max indecies be the left and right most
		minIndex = i;
		maxIndex = rightMost;
		for(int j = i + 1; j <= rightMost; j++){
			if(ascending){
				if(arr[j] <= arr[minIndex]){
					minIndex = j;
				}
				if(arr[j] >= arr[maxIndex]){
					maxIndex = j;
				}
			}else{
				if(arr[j] >= arr[minIndex]){
					minIndex = j;
				}
				if(arr[j] <= arr[maxIndex]){
					maxIndex = j;
				}
			}
		}

		
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;


		temp = arr[rightMost];
		arr[rightMost] = arr[maxIndex];
		arr[maxIndex] = temp;
		
		for(int k = 0; k < n; k++){
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;


		std::cout << i + 1 << " pass" << std::endl;
		std::cout << "Max Value: " << arr[rightMost] << std::endl << "Min Value: " << arr[i] << std::endl << std::endl;
	
		i++;
	}
};
#endif
