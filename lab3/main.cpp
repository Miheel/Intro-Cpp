#include <iostream>
#include <fstream>

#include "sorted.h"
#include "merge.h"

//Namn: Mikae Leuf
//Datum: 2019-11-26
//Kurs: Introduktion till programering
//Lab: lab3

int main()

{
	if(isSorted("A1"))//Check if file A1 is sorted
		std::cout << "File A1 is sorted" << std::endl;
	else
		std::cout << "File A1 is not sorted" << std::endl;
	

	if (isSorted("A") && isSorted("B"))//Check if file A and B are sorted if so proceed to merge the files to C
	{
		std::cout << "File A and B are sorted" << std::endl;

		merge("A", "B", "C");
		
		if (isSorted("C"))
			std::cout << "New file C is sorted" << std::endl;
		else
			std::cout << "New file C is not sorted" << std::endl;
	}

	return 0;
}
