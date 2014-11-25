#include "Trends.h"
#include <unordered_map>
#include <vector>

class ourTrends : public Trends {
public:
	ourTrends();
	~ourTrends();
	
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();
	

protected:
	
	unsigned int n;
	unsigned int* ints;
	std::vector<std::pair<std::string, unsigned int>> arr;
	std::unordered_map<std::string, unsigned int> ourMap; //created a hash table?
	bool isSorted = false;
};