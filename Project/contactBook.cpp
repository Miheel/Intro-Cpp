//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include "contactBook.h"

void add(const std::string &fileName)
{
	Contact contact;
	std::ofstream outFile(fileName, std::ofstream::app);

	//If the file couldnt be opend 
	//write error to the terminal and skip the rest
	if (!outFile.is_open()) 
	{
		std::cout << "Something went wrong, could not open the file" << std::endl;
	}
	else
	{
		std::cout << "Write the details of the person you would like to add as a contact" << std::endl;
		std::cout << "Name (Firstname Surename): ";
		isValidInput(contact.name, REGFILTER::NAME);

		std::cout << "Addres (Roadname number Ex:road 12): ";
		isValidInput(contact.addres, REGFILTER::ADDER);

		std::cout << "e-Mail (email@example.com): ";
		isValidInput(contact.eMail, REGFILTER::MAIL);

		std::cout << "PhoneNr (070-123 45 67): ";
		isValidInput(contact.phoneNr, REGFILTER::PHONE);

		std::cout << "BirthDay (nnnn-nn-nn): ";
		isValidInput(contact.birthDay, REGFILTER::DATE);

		std::cout << "Misc: ";
		isValidInput(contact.misc, REGFILTER::MISC);

		outFile << contact;

		outFile.close();
	}
}

void remove(const std::string &fileName)
{
	Contact contact;
	std::string searchTerm;
	std::vector<Contact> contactsToKeep;
	std::ifstream inFile(fileName);

	//If the file couldnt be opend 
	//write error to the terminal and skip the rest
	if (inFile.fail())
	{
		std::cout << "Something went wrong, could not open the file" << std::endl;
	}
	else
	{
		std::cout << "write a searchterm: ";
		std::getline(std::cin, searchTerm);

		std::string deleteChoice;

		//loop over the file
		while (inFile >> contact)
		{

			//compare the search term with read entry
			if (contact.find(searchTerm))
			{
				std::cout << "Do you wish to delete the found entry " << std::endl;
				std::cout << "delete (y/n) " << contact << std::endl;
				

				bool deleteLoop = true;
				while (deleteLoop)
				{

					std::getline(std::cin, deleteChoice);

					//deside if to delete entry or not
					if (deleteChoice[0] == 'n' && deleteChoice.size() == 1) 
					{
						contactsToKeep.push_back(contact);
						deleteLoop = false;
					}
					else if (deleteChoice[0] == 'y' && deleteChoice.size() == 1)
					{
						deleteLoop = false;
					}
					else
					{
						std::cout << "wrong input accepteble inputs is (y/n)" << std::endl;
						deleteLoop = true;
					}
				}
			}
			else
			{
				contactsToKeep.push_back(contact);
			}
		}

		//close the read file
		inFile.close();

		//open a new file to write to
		std::ofstream outFile(fileName);

		//If the file couldnt be opend 
		//write error to the terminal and skip the rest
		if (!outFile.is_open())
		{
			std::cout << "Something went wrong, could not open the file" << std::endl;
		}
		else
		{
			//loop over the vector of contacts to keep and write them to the file overwriting the old content
			for (auto keepIter = contactsToKeep.begin(); keepIter < contactsToKeep.end(); keepIter++)
			{
				outFile << *keepIter;
			}
			outFile.close();
		}
	}
}

void search(const std::string &fileName)
{
	Contact contact;
	int nrOfContactsFound = 0;
	std::string searchTerm;
	std::vector<Contact> foundContacts;
	std::ifstream inFile(fileName);

	//If the file couldnt be opend 
	//write error to the terminal and skip the rest
	if (inFile.fail())
	{
		std::cout << "Something went wrong, could not open the file" << std::endl;
	}
	else
	{
		std::cout << "Write a searchterm: ";
		std::getline(std::cin, searchTerm);

		while (inFile >> contact)
		{
			if (contact.find(searchTerm) == true)
			{
				foundContacts.push_back(contact);
				nrOfContactsFound++;
			}
		}

		//Write out nr of contacts found and all contacts found 
		std::cout << std::endl << "Number of contacts found for this searchterm is " << nrOfContactsFound << std::endl;
		for (auto iter = foundContacts.begin(); iter < foundContacts.end(); iter++)
		{
			std::cout << *iter << std::endl;
		}
		inFile.close();
	}
}