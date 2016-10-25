#ifndef FIFO_H
#define FIFO_H

//Author      : Suvojit Manna
//Application : vmPrism

//Header for First In First Out page replacement Policy API
//Replaces the page that is referenced most recently
//Calcultes Hit and Miss Ratio of the Algorithm
//@param  cacheSize   Number of frames the cache can hold
//@param  pageRefList List of page references in order of call

#include <queue>
#include <vector>
#include <unordered_set>

class FIFO
{
private:
	double hitRatio;	//store Hit Ratio
	size_t pageFaultCount;	//store no of page fault

public:
	//Constructor to create instances of FIFO
	//@param  cacheSize   Number of frames the cache can hold
	//@param  pageRefList List of page references in order of call
	FIFO(size_t cacheSize, std::vector<size_t> pageRefList);

	//Return the Hit Ratio
	//@param  void
	//@return Return the Hit Ratio
	double hit_ratio(void);

	//Return the Miss Ratio
	//@param  void
	//@return Return the Miss Ratio
	double miss_ratio(void);

	//Return the no of Page Fault
	//@param  void
	//@return Return no of page fault
	size_t page_fault(void);
};
#endif

