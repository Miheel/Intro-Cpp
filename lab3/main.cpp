#include <iostream>
#include <fstream>

#include "sorted.hpp"
#include "merge.hpp"
int main()

{
	if(isSorted("A1"))
		std::cout << "Is sorted" << std::endl;
	else
		std::cout << "Is not sorted" << std::endl;
	
	if (isSorted("A") && isSorted("B"))
		merge("A", "B", "C");
	
	if (isSorted("C"))
		std::cout << "Is sorted" << std::endl;
	else
		std::cout << "Is not sorted" << std::endl;

	return 0;
}
