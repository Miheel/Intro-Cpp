//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include "contact.h"

const char Contact::DELIMITER = '|';
const int Contact::NR_OF_MEMBERS = 6;

//Transform any given string of chars to uppercase.
std::string transformToupper(const std::string & other)
{
	std::string tmpStr;
	std::transform(other.begin(), other.end(), std::back_inserter(tmpStr), ::toupper);
	return tmpStr;
}

//Overloaded insertion << operator to write content of a struct.
std::ostream & operator<<(std::ostream & os, const Contact & other)
{
	return os << other.name << other.DELIMITER
		<< other.addres << other.DELIMITER
		<< other.eMail << other.DELIMITER
		<< other.phoneNr << other.DELIMITER
		<< other.birthDay << other.DELIMITER
		<< other.misc << other.DELIMITER << std::endl;
}

//Overloaded extraction >> operator to read content to a struct.
std::istream & operator>>(std::istream & is, Contact & other)
{
	std::string temparr[other.NR_OF_MEMBERS];

	for (int i = 0; i < other.NR_OF_MEMBERS; i++)
	{
		std::getline(is, temparr[i], other.DELIMITER);
	}

	//Remove any beginig newlines 
	if (temparr[0].front() == '\n')
	{
		temparr[0].erase(0, 1);
	}

	other.name = temparr[0];
	other.addres = temparr[1];
	other.eMail = temparr[2];
	other.phoneNr = temparr[3];
	other.birthDay = temparr[4];
	other.misc = temparr[5];

	return is;
}

//Returns true if a given case insensitive string exists in any struct member variable.
bool Contact::find(const std::string & sTerm)
{
	std::string tmpSTerm = transformToupper(sTerm);

	return (transformToupper(name).find(tmpSTerm) != -1) ||
		(transformToupper(addres).find(tmpSTerm) != -1) ||
		(transformToupper(eMail).find(tmpSTerm) != -1) ||
		(transformToupper(phoneNr).find(tmpSTerm) != -1) ||
		(transformToupper(birthDay).find(tmpSTerm) != -1) ||
		(transformToupper(misc).find(tmpSTerm) != -1);
}