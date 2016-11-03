# vmPrism
###Page Table Repacement Simulator

Compare diffrent page replacement algortihms.
***********
## Installing
To compile go to directory 
```
make
```
***********
##How to Use
```
./vmPrism <cache_size> <page_reference_list_file> <algorithm>
```
The program reads the page reference list and calcultes the simulates the passed algorithm on the given cache size.
Supported Algorithms - 
- [x] First In First Out (FIFO)
- [x] Least Recently Used (LRU)
- [x] Optimal (OPT)
  
Example -
If ```page_list.txt``` contains the following -
```
1 2 3 2 1 5 2 1 6 2 5 6 3 1 3 6 1 2 4 3
```
Using the following command to run FIFO on a Cache Size = 3 -
```
./vmPrism 3 page_list.txt FIFO
```
