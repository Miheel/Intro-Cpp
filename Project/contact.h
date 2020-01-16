#ifndef CONTACT_H
#define CONTACT_H

//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

/**
 *	A struct to represent a contact
 */
struct Contact
{
	std::string name;
	std::string addres;
	std::string eMail;
	std::string phoneNr;
	std::string birthDay;
	std::string misc;

	static const char DELIMITER; // A constant char to devide the members inside a file.
	static const int NR_OF_MEMBERS; // How many member variables the struct have

	/**
	 *	Returns true if a given case insensitive string exists in any struct member variable.
	 *
	 *	@param sTerm The string to find in the structs member variables.
	 *	@return a boolian value representing 
	 *	if the given string vas found in the struct.
	 */
	bool find(const std::string &sTerm);
};

/**
 *	Transform any given string of chars to uppercase.
 *
 *	@param other The string to transform.
 *	@return a new string transformed to uppercase.
 */
std::string transformToupper(const std::string &other);

/**
 *	Overloaded insertion << operator to write content of a contact struct.
 *
 *	@param other The struct to write to.
 */
std::ostream& operator<<(std::ostream& os, const Contact &other);

/**
 *	Overloaded extraction >> operator to read content to the contact struct.
 *
 *	@param other The struct to read from.
 */ 
std::istream& operator>>(std::istream& is, Contact &other);

#endif