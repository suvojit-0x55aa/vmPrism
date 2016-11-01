#ifndef OPT_H
#define OPT_H

//Author      : Suvojit Manna
//Application : vmPrism

//Header for Optimal/Bélády's optimal page replacement Policy API
//Replaces the page that will not be referenced for the longest time
//Calcultes Hit and Miss Ratio of the Algorithm
//@param  cacheSize   Number of frames the cache can hold
//@param  pageRefList List of page references in order of call

#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stddef.h>
#include <stdint.h>

class OPT
{
private:
	double hitRatio;	//store Hit Ratio
	size_t pageFaultCount;	//store no of page fault

	//Calculate forward distances of pages
	//The forward distance f(x) of page x is the no of time slots from
	//t to the first repeted reference of page x in future
	//f(x) = { k  , if k is the smallest integer such that r(t+k) = r(t) = x
	//       { inf, if x doesnot reappear after time t
	//@param  pageRefList List of page references in order of call
	//@param  fwdDistList List of forward distances
	void calc_fwd_dist(std::vector<size_t> &pageRefList,
		std::vector<size_t> &fwdDistList);

	//Return the page with max forward distance
	//NOTE : Erases the entry
	//@param  pageReplaceList A map containing (page -> fwdDist) map
	size_t erase_max(std::unordered_map<size_t, size_t> &pageReplaceList);

public:
	//Constructor to create instances of OPT
	//@param  cacheSize   Number of frames the cache can hold
	//@param  pageRefList List of page references in order of call
	OPT(size_t cacheSize, std::vector<size_t> pageRefList);

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
