#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <fstream>

bool comp(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2);

int main()
{
	std::ifstream inf("hitchhikersguide.txt");//Open the file
	
	std::map<std::string, int> freqMap;
	
	//Initialize two parallel vectors
	std::vector<std::string> wordList;
	std::vector<std::string>::iterator vecWordIter;
	std::vector<int> freqList;
	std::vector<int>::iterator vecFreqIter;
	
	std::string unFilteredWord;
	const int nrOfWords = 10;//Number of words to show

	//As long as there is words to be read from the file 
	while(inf >> unFilteredWord)
	{
		//Transform string to uppercase
		std::transform(unFilteredWord.begin(), unFilteredWord.end(), unFilteredWord.begin(), ::toupper);
		
		std::string filteredWord;	
		for(const char &ch: unFilteredWord)
		{
			if(isalnum(ch))
			{
				filteredWord += ch;//Build new string of only alphanum chars
			}
		}

		freqMap[filteredWord]++;//Increase the value of the key
	}
	
	for(int i = 0; i <= nrOfWords; i++)
	{
		//Find the biggest element in the map with self-constructed comp funk
		auto biggest = std::max_element(freqMap.begin(), freqMap.end(), comp);

		wordList.push_back(biggest->first);//Push the element key to word vector
		freqList.push_back(biggest->second);//Push toe element value to req vector
		freqMap.erase(biggest);//Remove the biggest element from the map
	}
	
	//Iterate through the two parallel vectors and print out the content
	vecWordIter = wordList.begin();
	vecFreqIter = freqList.begin();
	for(; vecWordIter < wordList.end(); vecWordIter++, vecFreqIter++)
	{		
		std::cout << *vecWordIter << " ==> " << *vecFreqIter << std::endl;
	}

	return 0;
}

bool comp(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2)
{
	return p1.second < p2.second;
}
