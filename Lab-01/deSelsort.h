#ifndef DESELSORT_H
#define DESELSORT_H
#include <iostream>

void deSelsort(int arr[], int n, bool ascending){
	int minIndex, maxIndex, temp, i = 0;
	while(i <= n-i-1){
		int rightMost = n-i-1;
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
