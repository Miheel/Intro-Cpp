#ifndef VALIDINPUT_H
#define VALIDINPUT_H

//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include <regex>
#include "contact.h"


enum REGFILTER {
	NAME,
	ADDER,
	MAIL,
	PHONE,
	DATE,
	MISC
};

/**
 *	Compares a given string with a regular expression,
 *	to determine if the string is a valid input.
 *
 *	@param contactmember The string to be compared with the regex.
 *
 *	@param regFilter A enum to determine with filter to use
 */
void isValidInput(std::string &contactMember, const REGFILTER &regFilter);

#endif