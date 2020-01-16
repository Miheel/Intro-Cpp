#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

//Namn: Mikael Leuf
//Datum: 2020-01-10
//Kurs: Introduktion till programering
//Lab: Project Contact

#include <vector>
#include "validInput.h"

/**
 *	Adds a contact to a file with help of user dialog.
 *
 *	@param fileName The name of the file of which to add the contact to.
 *
 */
void add(const std::string &fileName);

/**
 *	Remove a contact from a file with help of user dialog.
 *
 *	@param fileName The name of the file of which to remove the contact from.
 *
 */
void remove(const std::string &fileName);

/**
 *	Searches for a contact in a file with help of user dialog.
 *
 *	@param fileName The name of the file of which to search for a contact in.
 *
 */
void search(const std::string &fileName);

#endif