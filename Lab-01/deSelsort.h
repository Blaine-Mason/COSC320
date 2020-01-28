#ifndef DESELSORT_H
#define DESELSORT_H
#include <iostream>

void deSelsort(int arr[], int n, bool ascending){
	//left and right hold the current "state" of the algorithm
	//eg left = 1, right = n - 2 -> second iteration
	int minIndex, maxIndex, temp;
	int left = 0; 
	int right = n - 1;
	while(left < right){
		minIndex = left;
		maxIndex = right;
		for(int i = left + 1; i < right; i++){
			if(arr[i] < arr[minIndex]){
				minIndex = i;
			}
			if(minIndex != left){
				temp = arr[left];
				arr[left] = arr[minIndex];
				arr[minIndex] = temp; 
			}
			for(int j = right - 1; j > left; j--){
				if(arr[j] > arr[maxIndex]){
					maxIndex = j;
				}
				if(maxIndex != right){
					temp = arr[right];
					arr[right] = arr[maxIndex];
					arr[maxIndex] = temp;

				}
			}

		}
	left++;
	right--;
	}
};
#endif