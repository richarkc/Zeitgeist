#include "ourTrends.h"

#include <algorithm>
#include <string>
#include <iostream>




bool isSorted;

ourTrends::ourTrends() {
	ints = new unsigned int[10000];
	n = 0;
}

void ourTrends::increaseCount(std::string s, unsigned int amount){
	
	
	std::unordered_map<std::string, unsigned int>::iterator found = ourMap.find(s);

	//element does not exist
	if (found == ourMap.end()) { 
		ints[n] = amount;
		std::pair<std::string, unsigned int> p = std::make_pair(s, n);
		ourMap.insert(p);
		arr.push_back(p);
		n++;
	}

	else { //element does exist so update the amount
		ints[found->second] += amount;
		
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
	return ints[a];
	
}




std::string ourTrends::getNthPopular(unsigned int n){
	if (!isSorted){
		std::sort(arr.begin(), arr.end(), [this](const std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j) 
		{if (ints[i.second] == ints[j.second]){
			return (i.first < j.first);
		}

		return (ints[i.second] > ints[j.second]); });
		isSorted = true;
	}
	if (n <= numEntries()){
		return arr[n].first;
		
	}
	//If they give bad input, return empty string.
	return "";
	
	
}

unsigned int ourTrends::numEntries(){
	return ourMap.size(); //radical
}