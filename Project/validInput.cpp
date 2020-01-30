//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include "validInput.h"

void isValidInput(std::string &contactMember, const REGFILTER &regFilter)
{
	bool isValid = false;
	std::regex regularFilter;
	std::string errFormMsg = "The string must be on the specified format: ";
	std::string errContMsg = "Can only contain the folowing characters";
	while (!isValid)
	{
		std::getline(std::cin, contactMember);

		switch (regFilter)
		{
		case NAME:
			regularFilter = ("[A-Za-z ]+");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errFormMsg << "Forename surename" << std::endl;

			break;

		case ADDER:
			regularFilter = ("[A-Za-z- ]+ [0-9]+");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errFormMsg << "Roadname nr" << std::endl;

			break;

		case MAIL:
			regularFilter = ("[A-Za-z0-9._%+-]{1,20}@[A-Za-z0-9-]{2,20}(\\.[A-Za-z]{2,3}){1,2}");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errFormMsg << "(email@example.com)\n" << errContMsg << "Letters, Numbers and '._%+-'" << std::endl;

			break;

		case PHONE:
			regularFilter = ("[0-9]{3}[-][0-9]{3} [0-9]{2} [0-9]{2}");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errFormMsg << "070-123 45 67" << std::endl;

			break;

		case DATE:
			regularFilter = ("[0-9]{4}-[0-9]{2}-[0-9]{2}");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errFormMsg << "nnnn-nn-nn" << std::endl;

			break;

		case MISC:
			regularFilter = ("[^|]+");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << "the string cant contain the pipe char '|'" << std::endl;

			break;
		}
	}
}