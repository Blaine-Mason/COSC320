#ifndef DESELSORT_H
#define DESELSORT_H
#include <iostream>

void deSelsort(int arr[], int n, bool ascending){
	//left and right hold the current "state" of the algorithm
	//eg left = 1, right = n - 2 -> second iteration
	int minIndex, maxIndex, temp, i = 0;
	while(i <= n-i-1){
		minIndex = i;
		maxIndex = n-i-1;
		for(int j = i + 1; j <= n-i-1; j++){
			if(arr[j] <= arr[minIndex]){
				minIndex = j;
			}
			if(arr[j] >= arr[maxIndex]){
				maxIndex = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;


		temp = arr[n-i-1];
		arr[n-i-1] = arr[maxIndex];
		arr[maxIndex] = temp;

		i++;
	}
};
#endif
