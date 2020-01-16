//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include "validInput.h"

//Compares a given string with a regular expression,to determine if the string is a valid input.
void isValidInput(std::string &contactMember, const REGFILTER &regFilter)
{
	bool isValid = false;
	std::regex regularFilter;
	std::string errMsg = "The line can only contain the folowing characters: ";

	while (!isValid)
	{
		std::getline(std::cin, contactMember);

		switch (regFilter)
		{
		case NAME:
			regularFilter = ("[^|]+");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errMsg << "Letters" << std::endl;

			break;

		case ADDER:
			regularFilter = ("[A-Za-z- ]+ [0-9]+");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errMsg << "Letters Numbers '-' and space" << std::endl;

			break;

		case MAIL:
			regularFilter = ("[A-Za-z0-9._%+-]{1,20}@[A-Za-z0-9-]{2,20}(\.[A-Za-z]{2,3}){1,2}");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errMsg << "Letters Numbers and '._%+-'" << std::endl;

			break;

		case PHONE:
			regularFilter = ("[0-9]{3}[-][0-9]{3} [0-9]{2} [0-9]{2}");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errMsg << "Numbers and '-'" << std::endl;

			break;

		case DATE:
			regularFilter = ("[0-9]{4}-[0-9]{2}-[0-9]{2}");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errMsg << "Numbers and '-'" << std::endl;

			break;

		case MISC:
			regularFilter = ("[^|]+");

			if (std::regex_match(contactMember, regularFilter)) isValid = true;

			else std::cout << errMsg << "Letters and numbers" << std::endl;

			break;
		}
	}
}