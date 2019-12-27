#include <iostream>
#include "deSelsort.h"

int main(){
	int a[8] = {13, 5, 2, 25, 47, 17, 8, 21};
	deSelsort(a, 8, true);
	for(int i = 0; i < 8; i++){
		std::cout << a[i] << " "; 
	}
	std::cout << std::endl;

	return 0;
}