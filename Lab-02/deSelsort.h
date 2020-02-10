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
	while(leftMost <= n-leftMost-1){
		//rightMost -> holds the index of the right most position
		int rightMost = n-leftMost-1;

		//left the min and max indecies be the left and right most
		minIndex = leftMost;
		maxIndex = rightMost;
		//walk the array finding the min and max indicies
		for(int j = leftMost + 1; j <= rightMost; j++){
			//if ascending is true sort in ascending order else, descending
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

		//perform the swap for the minimum element
		//temp -> left most value
		//arr[leftMost] -> value of minimum element
		//arr[minIndex] -> left most value 
		temp = arr[leftMost];
		arr[leftMost] = arr[minIndex];
		arr[minIndex] = temp;
		swapCount++;
		
		//perform the swap for the maximum element
		//temp -> right most value
		//arr[rightMost] -> maximum element
		//arr[maxIndex] -> right most value
		// 
		temp = arr[rightMost];
		arr[rightMost] = arr[maxIndex];
		arr[maxIndex] = temp;
		swapCount++;
		
		//display the array for each iteration of the while loop
		//for(int k = 0; k < n; k++){
			//std::cout << arr[k] << " ";
		//}
		//std::cout << std::endl;
		
		//Display info for algorithm analysis
		//std::cout << leftMost + 1 << " pass" << std::endl;
		//std::cout << "Max Value: " << arr[rightMost] << std::endl << "Min Value: " << arr[leftMost] << std::endl;
		
		//std::cout << "Total Swaps: " << swapCount << std::endl << std::endl;
		
		//increase the leftMost in order to shift the rightMost left ex:
		//[0,   0,    9,   3,   2,   4]
		// ^-leftMost       rightMost^
		//post increase:
		//[0,   0,    9,   3,   2,   4]
		//			^-leftMost      ^-rightMost
		leftMost++;
	}
};
#endif
