#include <iostream>
#include <fstream>

#include "include/sorted.hpp"

int main()

{
	std::ifstream inFile1, inFile2;

	inFile1.open("a.txt");
	inFile2.open("b.txt");

	bool sortBool = isSorted(/*inFile1, inFile2*/);
	
	std::cout << sortBool << std::endl;

	return 0;
}
