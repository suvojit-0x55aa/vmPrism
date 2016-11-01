#include <iostream>
#include <fstream>
#include <string>
#include "FIFOPolicy.h"
#include "LRUPolicy.h"
#include "OPTPolicy.h"

int main(int argc, char** argv)
{
	// Checking if the number of parameter is equal 4
	// alerting the user if not
	if (argc < 4)
	{
		std::cout << "Expecting more parameters:\n" <<
			"./vmPrism buffer_size file type\n" <<
			"buffer_size: size of buffer (int)\n" <<
			"file: filenames with the data\n" <<
			"type: replacement Algorithm (FIFO, LRU, OPT)" << std::endl;
		return 1;
	}
	if (argc > 4)
	{
		std::cout << "Too many parameters:\n" <<
			"./vmPrism buffer_size file type\n" <<
			"buffer_size: size of buffer (int)\n" <<
			"file: filenames with the data\n" <<
			"type: replacement Algorithm (FIFO, LRU, OPT)" << std::endl;
		return 1;
	}

	// Verify if the second parameter is a valid integer or not
	// dealing with the exception and alerting the user
	size_t cacheSize;
	try
	{
		cacheSize = std::stoi(argv[1], nullptr);
	}
	catch (...)
	{
		std::cout << "Can't convert second parameter '" << argv[1] <<
			"' into an integer" << std::endl;
		return 1;
	}

	// Check if the file is a valid file and extract all the data
	// the data need to be integer separated by spaces
	// IT DOESN'T CHECK IF THE FILE HAS ONLY INTEGER VALUES
	std::vector<size_t> refList;
	std::ifstream page_list(argv[2]);
	if (page_list.is_open())
	{
		size_t a;
		while (page_list >> a)
			refList.push_back(a);
		page_list.close();
	}
	else
	{
		std::cout << "Can't open the specified file: " << argv[2] << std::endl;
		return 1;
	}

	// Check the last parameter, if it is a valid replace algorithm name
	// If not, a message will be delivered to the user
	std::string algorithm(argv[3]);
	if (algorithm.compare("FIFO") == 0)
	{
		FIFO cal(cacheSize, refList);
		std::cout << cal.hit_ratio() << std::endl;
		std::cout << cal.miss_ratio() << std::endl;
		std::cout << cal.page_fault() << std::endl;
	}
	else if (algorithm.compare("LRU") == 0)
	{
		 LRU cal(cacheSize, refList);
		 std::cout << cal.hit_ratio()  << std::endl;
		 std::cout << cal.miss_ratio() << std::endl;
		 std::cout << cal.page_fault() << std::endl;
	}
	else if (algorithm.compare("OPT") == 0)
	{
		 OPT cal(cacheSize, refList);
		 std::cout << cal.hit_ratio()  << std::endl;
		 std::cout << cal.miss_ratio() << std::endl;
		 std::cout << cal.page_fault() << std::endl;
	}
	else
	{
		std::cout << "The third parameter must be a valid replacement" <<
			" Algorithm (FIFO, LRU or OPT)" << std::endl;
		return 1;
	}
	return 0;
}