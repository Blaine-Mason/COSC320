#include <iostream>
#include "deSelsort.h"
#include <cstdlib>


/* Author: Blaine Mason
 * Date: 2 Feburary 2020
 * Description: This sorting algorithm is a modification of seclection
 * 							sort where it starts from both ends and searchs for the
 *							max and min, then sets those values to the left most
 *							index and right most index respectively.
*/

int main(){

	srand(time(0));
	//Sample Array 
	int a[8] = {13, 5, 2, 25, 47, 17, 8, 21};
	int b[1000];
	
	for(int i = 0; i < 1000; i++){
		b[i] = rand()%100;
	}
	
	deSelsort(a, 8, false);

	std::cout << "Final Array Sorted: " << std::endl;
	
	for(int i = 0; i < 8; i++){
		std::cout << a[i] << " "; 
	}
	std::cout << std::endl;

	return 0;
}
