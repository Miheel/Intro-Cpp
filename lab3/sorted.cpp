#include "sorted.h"

//Namn: Mikael Leuf
//Datum: 2019-11-26
//Kurs: Introduktion till programering
//Lab: lab3

bool isSorted(std::string fileName)
{
	std::ifstream inFile;
	inFile.open(fileName);//Open file

	int current, previous;
	 
	inFile >> previous;

	//As long as there is content to be rad from the file
	while(inFile >> current)
	{
		//If the previous nr is bigger than the current nr
		//the file is unsorted
		if(previous>current)
		{
			inFile.close();
			return false;
		}

		//Make previous the current nr
		previous = current;
	}

	inFile.close();
	return true;
}

