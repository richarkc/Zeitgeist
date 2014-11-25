#include "ourTrends.h"
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>

std::unordered_map<std::string, unsigned int*> ourMap; //created a hash table?
std::map<unsigned int, std::string> BST;

void ourTrends::increaseCount(std::string s, unsigned int amount){
	
	
	std::unordered_map<std::string, unsigned int*>::iterator found = ourMap.find(s);

	if (found == ourMap.end()) { 
		unsigned int j = amount;
		ourMap.insert(std::make_pair(s,&j));
		BST.insert(std::make_pair(j, s));
	}

	else { //element does exist so update the amount
		
	}
}

unsigned int ourTrends::getCount(std::string s){
	//Check to see if word is present
	unsigned int* a;
	try
	{
		a = ourMap.at(s);
	}
	catch (const std::out_of_range s)
	{
		return 0;
	}
	return *a;
	
}



std::string ourTrends::getNthPopular(unsigned int n){
	/*Brinkman's Code
	std::sort(wordCountVector.begin(), wordCountVector.end(), compareFunc);
	if (n <= numEntries()){
		return wordCountVector[n].first;
	}

	//If they give bad input, return empty string.
	return "";
	*/
	return "";
}

unsigned int ourTrends::numEntries(){
	return wordCountVector.size(); //Brinkman's Code
}