#include <iostream>
#include <fstream>

#include "sorted.hpp"
#include "merge.hpp"

//Name: Mikae Leuf
//Datum: 2019-11-26
//Kurs: Introduktion till programering
//Lab: lab3

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
