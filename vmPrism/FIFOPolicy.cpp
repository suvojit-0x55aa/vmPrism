#include "FIFOPolicy.h"

//Author      : Suvojit Manna
//Application : vmPrism

//Constructor to create instances of FIFO
FIFO::FIFO(size_t cacheSize, std::vector<size_t> pageRefList)
{
	size_t hitCount = 0;
	std::queue<size_t> pageReplaceList;
	std::unordered_set<size_t> pageCache;
	for (const int &page : pageRefList)
	{
		if (pageCache.find(page) != pageCache.end())
			hitCount++;
		else if (pageCache.size() == cacheSize)
		{
			size_t replacePage = pageReplaceList.front();
			pageReplaceList.pop();
			pageCache.erase(replacePage);
			pageReplaceList.push(page);
			pageCache.insert(page);
		}
		else
		{
			pageCache.insert(page);
			pageReplaceList.push(page);
		}
	}

	hitRatio = ((double) hitCount) / pageRefList.size();
	pageFaultCount = pageRefList.size() - hitCount;
}

//Return the Hit Ratio
double FIFO::hit_ratio(void)
{
	return hitRatio;
}

//Return the Miss Ratio
double FIFO::miss_ratio(void)
{
	return 1.0 - hitRatio;
}

//Return the no of Page Fault
size_t FIFO::page_fault(void)
{
	return pageFaultCount;
}
