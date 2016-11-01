#include "OPTPolicy.h"
#include <iostream>

//Author      : Suvojit Manna
//Application : vmPrism

//Constructor to create instances of OPT
OPT::OPT(size_t cacheSize, std::vector<size_t> pageRefList)
{
	size_t hitCount = 0;
	//calculate forward Distances
	std::vector<size_t> fwdDistList;	//store forward distance
	calc_fwd_dist(pageRefList, fwdDistList);

	std::unordered_set<size_t> pageCache;
	std::unordered_map<size_t, size_t> pageReplaceList;
	for (size_t pageIdx = 0; pageIdx < pageRefList.size(); ++pageIdx)
	{
		size_t page = pageRefList[pageIdx];
		if (pageCache.find(page) != pageCache.end())
		{
			hitCount++;
			//update new forward distance
			pageReplaceList[page] = fwdDistList[pageIdx];
		}
		else if (pageCache.size() == cacheSize)
		{
			size_t replacePage = erase_max(pageReplaceList);
			pageCache.erase(replacePage);
			std::pair<size_t, size_t> distPair(page, fwdDistList[pageIdx]);
			pageReplaceList.insert(distPair);
			pageCache.insert(page);
		}
		else
		{
			std::pair<size_t, size_t> distPair(page, fwdDistList[pageIdx]);
			pageReplaceList.insert(distPair);
			pageCache.insert(page);
		}
	}

	hitRatio = ((double)hitCount) / pageRefList.size();
	pageFaultCount = pageRefList.size() - hitCount;
}

//Calculate forward distances of pages
void OPT::calc_fwd_dist(std::vector<size_t> &pageRefList,
	std::vector<size_t> &fwdDistList)
{
	fwdDistList.resize(pageRefList.size());
	std::unordered_map<size_t, size_t> indexMap;
	for (int i = pageRefList.size() - 1; i >= 0; --i)
	{
		//if the page doesnt reappear in future
		if (indexMap.find(pageRefList[i]) == indexMap.end())
		{
			std::pair<size_t, size_t> pageIndex(pageRefList[i], i);
			indexMap.insert(pageIndex);
			fwdDistList[i] = UINT64_MAX;
		}
		else
		{
			fwdDistList[i] = indexMap[pageRefList[i]] - i;
			indexMap[pageRefList[i]] = i;
		}
	}
}

//Return the page with max forward distance
size_t OPT::erase_max(std::unordered_map<size_t, size_t> &pageReplaceList)
{
	size_t max = (*pageReplaceList.begin()).second;
	size_t page = (*pageReplaceList.begin()).first;
	for (auto &dist : pageReplaceList)
		if (dist.second > max)
		{
			max  = dist.second;
			page = dist.first;
		}
	pageReplaceList.erase(page);
	return page;
}

//Return the Hit Ratio
double OPT::hit_ratio(void)
{
	return hitRatio;
}

//Return the Miss Ratio
double OPT::miss_ratio(void)
{
	return 1.0 - hitRatio;
}

//Return the no of Page Fault
size_t OPT::page_fault(void)
{
	return pageFaultCount;
}
