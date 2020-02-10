#include <iostream>
#include "binSearch.h"
#include <cstdlib>


int main(){
	srand(time(0));
	int ARRSIZE = 10000;
	int arr[ARRSIZE];
	int RANDOMLIMIT = 99999;
	int RANDOMVALUES = 10000;

	for(int i = 0; i < ARRSIZE; i++){
		arr[i] = rand()%RANDOMLIMIT;
	}
	int sumFailCom = 0;
	int temp = 0;
	int successTotal = 0;
	for(int j = 0; j < RANDOMVALUES; j++){
		int randomTarget = rand()%RANDOMLIMIT;
		int indexOfItem = binSearch(arr, ARRSIZE, randomTarget, temp);
		if(indexOfItem == -1){
			indexOfItem = binSearch(arr, ARRSIZE, randomTarget, sumFailCom);
		}else{
			successTotal++;
		}
		std::cout << j << std::endl;
		std::cout << successTotal << std::endl;
		std::cout << sumFailCom << std::endl;
	}
		
	return 0;
}
