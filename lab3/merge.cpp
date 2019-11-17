#include "merge.hpp"

void merge(std::string fileName1, std::string fileName2, std::string mergedFile)
{
	std::ifstream inFile1(fileName1), inFile2(fileName2);
	std::ofstream outfile(mergedFile);
	int inFromFile1, inFromFile2, row = 0;

	inFile1 >> inFromFile1;
	inFile2 >> inFromFile2;
		
	while(!inFile1.eof() && !inFile2.eof())
	{
		
		row++;
		if(inFromFile1 < inFromFile2)
		{
			outfile << inFromFile1 << " ";
			inFile1 >> inFromFile1;
		}
		else
		{
			outfile << inFromFile2 << " ";
			inFile2 >> inFromFile2;
		}
		
		if(row % 10 == 0)
			outfile << "\n";
	}
		
	while(!inFile1.eof())
	{
		outfile << inFromFile1 << " ";
		inFile1 >> inFromFile1;
	}
	
	while(!inFile2.eof())
	{
		outfile << inFromFile2 << " ";
		inFile2 >> inFromFile2;
	}

	inFile1.close();
	inFile2.close();
	outfile.close();
}
