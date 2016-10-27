#include "LRUPolicy.h"

//Author      : Suvojit Manna
//Application : vmPrism

//Constructor to create instances of LRU
LRU::LRU(size_t cacheSize, std::vector<size_t> pageRefList)
{
	size_t hitCount = 0;
	std::list<size_t> pageReplaceList;
	std::unordered_set<size_t> pageCache;
	for (const int &page : pageRefList)
	{
		if (pageCache.find(page) != pageCache.end())
		{
			hitCount++;
			pageReplaceList.remove(page);
			pageReplaceList.push_front(page);
		}
		else if (pageCache.size() == cacheSize)
		{
			size_t replacePage = pageReplaceList.back();
			pageReplaceList.remove(replacePage);
			pageCache.erase(replacePage);
			pageReplaceList.push_front(page);
			pageCache.insert(page);
		}
		else
		{
			pageCache.insert(page);
			pageReplaceList.push_front(page);
		}
	}

	hitRatio = ((double) hitCount) / pageRefList.size();
	pageFaultCount = pageRefList.size() - hitCount;
}

double LRU::hit_ratio(void)
{
	return hitRatio;
}

//Return the Miss Ratio
double LRU::miss_ratio(void)
{
	return 1.0 - hitRatio;
}

//Return the no of Page Fault
size_t LRU::page_fault(void)
{
	return pageFaultCount;
}
