#include <iostream>
#include <string>
#include <fstream>

//Namn: Mikael Leuf
//Datum: 2019-11-25
//Kurs: DT028G_DT178G - Introduktion till programering
//Lab: lab2

int main()
{
	std::ifstream inFile;
	std::string foreName, surName, personID, road;
	std::string gender = " [ ]";
	
	//open the file for reading
	inFile.open("names.txt");
	
	while(getline(inFile, foreName, ' ')) //read to the next space in to foreNme
	{
		getline(inFile, surName); //read the rest of the line in to surName
		getline(inFile, personID);//read the other lines to the assigned variables
		getline(inFile, road);
		
		//cast the 9th character to an int and subtract the ascii value of 0 to get the value between 0-9
		//determine if the number if evenly divisible by 2
		//if thats the case set gender to 'F' otherwise set 'M'
		if ((static_cast<int>(personID[8]) - '0') % 2 == 0)
			gender[2] = 'F';
		else
			gender[2] = 'M';
		
		//print the names
		std::cout << surName << ", " << foreName << gender << std::endl << road << std::endl;
	}
	
	//close the file
	inFile.close();
	return 0;
}
