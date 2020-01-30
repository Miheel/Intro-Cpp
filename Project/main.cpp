//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include <limits>
#include "contactBook.h"

int main()
{
	std::string menueChoice;
	bool menueLoop = true;
	std::string fileName = "contactList";

	std::cout << "Welcome to contactbook" << std::endl;
	std::cout << "what would you like to do" << std::endl;

	while (menueLoop == true)
	{
		std::cout << "(A)dd (R)emove (S)earch (Q)uit" << "\n\n";

		std:getline(std::cin, menueChoice);

		if (menueChoice.size() != 1) //ensures that only string size of one makes for valid input
		{
			menueChoice = '1';
		}

		//switch statement to switch around index 0 of input string
		switch (menueChoice[0])
		{
		case 'A':
		case 'a':
			std::cout << "Add contact" << std::endl;
			add(fileName);
			break;

		case 'R':
		case 'r':
			std::cout << "Remove contacts" << std::endl;
			remove(fileName);
			break;

		case 'S':
		case 's':
			std::cout << "Search for contacts" << std::endl;
			search(fileName);
			break;

		case 'Q':
		case 'q':
			//Quitting program
			menueLoop = false;
			break;

		default:
			std::cout << "Invalid input try again" << std::endl;
			break;
		}
	}
	return 0;
}