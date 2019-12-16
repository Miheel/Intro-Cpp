#include "merge.h"

//Namn: Mikael Leuf
//Datum: 2019-11-26
//Kurs: Introduktion till programering
//Lab: lab3

void merge(std::string fileName1, std::string fileName2, std::string mergedFile)
{
	std::ifstream inFile1(fileName1), inFile2(fileName2);//Open the files
	std::ofstream outfile(mergedFile);
	int inFromFile1, inFromFile2, row = 0;

	//Read start values from both files
	inFile1 >> inFromFile1;
	inFile2 >> inFromFile2;
		
	//as long as we haven't reached the end of ether file 
	while(!inFile1.eof() && !inFile2.eof())
	{
		
		row++;
		//If the nr from file1 is less than file2 
		//write that nr to a new file and read a new nr from file1
		if(inFromFile1 < inFromFile2)
		{
			outfile << inFromFile1 << " ";
			inFile1 >> inFromFile1;
		}
		
		//else write the nr from file2 to oute file
		//and read from file2
		else
		{
			outfile << inFromFile2 << " ";
			inFile2 >> inFromFile2;
		}
		
		//when 10 writes to the out file has happend insert a newline 
		if(row % 10 == 0)
			outfile << "\n";
	}
	
	//If there are content still in file1 write them to the outfile
	while(!inFile1.eof())
	{
		row++;
		outfile << inFromFile1 << " ";
		inFile1 >> inFromFile1;
		if(row % 10 == 0)
			outfile << "\n";


	}

	//If there are content still in file2 write them to the outfile
	while(!inFile2.eof())
	{
		row++;
		outfile << inFromFile2 << " ";
		inFile2 >> inFromFile2;
		if(row % 10 == 0)
			outfile << "\n";

	}

	//Close all files
	inFile1.close();
	inFile2.close();
	outfile.close();
}
