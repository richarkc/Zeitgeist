#include "naiveTrends.h"
#include <algorithm>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> ourMap; //created a hash table?

void naiveTrends::increaseCount(std::string s, unsigned int amount){
	//Check to see if word is already present
	
	std::unordered_map<std::string, std::string>::iterator found = ourMap.find(s);

	if (found == ourMap.end()) { //element dos not exist in hash table
		//need to add new element to hash table
		//check vector first?
	}

	else { //element does exist so update the amount
		found->second = amount;
	}
}

unsigned int naiveTrends::getCount(std::string s){
	//Check to see if word is present
	return ourMap.size();
}

//Keeping Brinkman's code for this method
bool compareFunc(std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j) {
	if (i.second == j.second){
		return (i.first < j.first);
	}

	return (i.second > j.second);
}

std::string naiveTrends::getNthPopular(unsigned int n){
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

unsigned int naiveTrends::numEntries(){
	return wordCountVector.size(); //Brinkman's Code
}