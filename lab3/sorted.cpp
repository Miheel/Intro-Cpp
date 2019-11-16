#include "sorted.hpp"

bool isSorted(std::string fileName)
{
	std::ifstream inFile;
	inFile.open(fileName);

	int current, previous;
	inFile >> previous;

	while(inFile >> current)
	{
		if(previous>current)
		{
			return false;
		}
		previous = current;
	}
	return true;
}

