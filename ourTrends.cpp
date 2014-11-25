#include "ourTrends.h"

#include <algorithm>
#include <string>
#include <iostream>




bool isSorted;

void ourTrends::increaseCount(std::string s, unsigned int amount){
	
	
	std::unordered_map<std::string, unsigned int*>::iterator found = ourMap.find(s);

	//element does not exist
	if (found == ourMap.end()) { 
		unsigned int j = amount;
		ourMap.insert(std::make_pair(s,&j));
		arr.push_back(std::make_pair(&j,s));
	}

	else { //element does exist so update the amount
		*(found->second) += amount;
	}
	isSorted = false;
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

bool compareFunc(std::pair<unsigned int*, std::string> i, std::pair<unsigned int*, std::string> j) {
	if (*(i.first) == *(j.first)){
		return (i.second < j.second);
	}

	return (*(i.first) > *(j.first));
}

std::string ourTrends::getNthPopular(unsigned int n){
	if (isSorted)
		std::sort(arr.begin(), arr.end(), compareFunc);
	if (n <= numEntries()){
		return arr[n].second;
		
	}
	//If they give bad input, return empty string.
	return "";
	
	
}

unsigned int ourTrends::numEntries(){
	return ourMap.size(); //radical
}