#include <iostream>
#include "binSearch.h" //which also #include "deSelSort.h"
#include <cstdlib> //used for srand(time(0))


int main(){
  //Seed the random variables
	srand(time(0));

  //Predefined variables from the Lab instructions
	int ARRSIZE = 10000;
	int arr[ARRSIZE];
	int RANDOMLIMIT = 99999;
	int RANDOMVALUES = 10000;
  
  //A for-loop to fill the array with random values from 
  //0-RANDOMLIMIT
	for(int i = 0; i < ARRSIZE; i++){
		arr[i] = rand()%RANDOMLIMIT;
	}
  //Sort the entire array using deSelsort 
  //defined in Lab-01
	deSelsort(arr, ARRSIZE);
    
  //sumFailCom -> the sum of the comparisons during a
  //failed search(item DNE in array
  //temp -> a temporary integer to pass into binSearch to 
  //see if the RANDOM target can be found(return value != -1)
  //successTotal -> the sum of the  total successful searches
	int sumFailCom = 0;
	int temp = 0;
	int successTotal = 0;
  
  //Loop iterates RANDOMVALUES-number of times
	for(int j = 0; j < RANDOMVALUES; j++){
    //randomTarget -> a random target that will be unique each iteration
		int randomTarget = rand()%RANDOMLIMIT;
    
    //indexOfItem -> stores the index the item exits, if successful,
    //then this will be the index, else, unsuccessful
    //the effectiveness of temp:
    //  temp will be passed into binSearch by reference to count the comparisons, 
    //  but the only comparisons we are worried about is if the target value is not value.
    //  so if a successful search is performed then the use of sumFailCom would be ruined.
    //  By using temp you get if a successful search exits, from there you either increment
    //  successTotal, or run binSearch again, since you know it will fail, to get the sumFailCom.
		int indexOfItem = binSearch(arr, ARRSIZE, randomTarget, temp);
		if(indexOfItem == -1){
			indexOfItem = binSearch(arr, ARRSIZE, randomTarget, sumFailCom);
		}else{
			successTotal++;
		}
	}
  //As expected the worst case for binary search is log(n), for instance, 
  //if ARRSIZE is 10000, then the log(n) returns 13  
	std::cout << "Comparison for Fail: " << sumFailCom << std::endl;
	std::cout << "Successful Searches: " << successTotal << std::endl;
	std::cout << "Worst Case: " << (double)(sumFailCom)/(RANDOMVALUES - successTotal) << std::endl;
		
	return 0;
}
