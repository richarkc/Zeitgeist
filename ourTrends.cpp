#include "ourTrends.h"

#include <algorithm>
#include <string>
#include <iostream>




bool isSorted;

void ourTrends::increaseCount(std::string s, unsigned int amount){
	
	
	std::unordered_map<std::string, unsigned int>::iterator found = ourMap.find(s);

	//element does not exist
	if (found == ourMap.end()) { 
		unsigned int j = amount;
		std::pair<std::string, unsigned int> p = std::make_pair(s, j);
		ourMap.insert(p);
		arr.push_back(p);
	}

	else { //element does exist so update the amount
		(found->second) += amount;
	}
	isSorted = false;
}

unsigned int ourTrends::getCount(std::string s){
	//Check to see if word is present
	unsigned int a;
	try
	{
		a = ourMap.at(s);
	}
	catch (const std::out_of_range s)
	{
		return 0;
	}
	return a;
	
}

bool compareFunc(std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j) {
	if (i.second == j.second){
		return (i.first < j.first);
	}

	return (i.second > j.second);
}

std::string ourTrends::getNthPopular(unsigned int n){
	if (isSorted)
		std::sort(arr.begin(), arr.end(), compareFunc);
	if (n <= numEntries()){
		return arr[n].first;
		
	}
	//If they give bad input, return empty string.
	return "";
	
	
}

unsigned int ourTrends::numEntries(){
	return ourMap.size(); //radical
}