#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <fstream>

//Namn: Mikael Leuf
//Datum: 2019-12-09
//Kurs: Introduktion till programering
//Lab: lab4

bool comp(const std::pair<std::string, int> &comp1, const std::pair<std::string, int> &comp2);

int main()
{

	std::ifstream inf("hitchhikersguide.txt");//Open the file

	std::map<std::string, int> freqMap;

	//Initialize two parallel vectorts
	std::vector<std::string> wordList;
	std::vector<std::string>::iterator vecWordIter;
	std::vector<int> freqList;
	std::vector<int>::iterator vecFreqIter;

	std::string unFilteredWord;
	const int nrOfWords = 20;//Number of words to show

	//As long as there are are content to be read from the file
	while(inf >> unFilteredWord)
	{
		//Transforn string to uppercase
		std::transform(unFilteredWord.begin(), unFilteredWord.end(), unFilteredWord.begin(), ::toupper);
	
		std::string filteredWord;	
		for(const char &ch: unFilteredWord)
		{
			if(isalnum(ch))
			{
				filteredWord += ch;//Make a new string of only alphanumerical characters
			}
		}
		
		//If a string exist add it to the map and increase the value of the key
		if(!filteredWord.empty())
		{
			freqMap[filteredWord]++;
		}
	}
	
	inf.close();

	for(int i = 0; i < nrOfWords; i++)
	{
		//Find the biggest element value in he map with a custom compare funktion
		auto biggest = std::max_element(freqMap.begin(), freqMap.end(), comp);
		
		//Push the key and value to the vectors
		wordList.push_back(biggest->first);
		freqList.push_back(biggest->second);
		
		//Remove the biggest element from the map 
		freqMap.erase(biggest);
	}
	
	//iterate over the vectors and print out the content
	vecWordIter = wordList.begin();
	vecFreqIter = freqList.begin();
	for(; vecWordIter < wordList.end(); vecWordIter++, vecFreqIter++)
	{		
		std::cout << *vecWordIter << " ==> " << *vecFreqIter << std::endl;
	}
		
	return 0;
}

bool comp(const std::pair<std::string, int> &comp1, const std::pair<std::string, int> &comp2)
{
	return comp1.second < comp2.second;
}
