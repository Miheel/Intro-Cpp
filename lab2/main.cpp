#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inFile;
	std::string foreName, surName, personID, road;
	std::string gender = " [ ]";
	
	inFile.open("names.txt");
	
	while(getline(inFile, foreName, ' '))
	{
		getline(inFile, surName);
		getline(inFile, personID);
		getline(inFile, road);
		
		if (static_cast<int>(personID[8]) % 2 == 0)
			gender[2] = 'F';
		else
			gender[2] = 'M';

		std::cout << surName << ", " << foreName << gender << std::endl << road << std::endl;
	}

	inFile.close();
	return 0;
}
