run:
	g++ vmPrism/FIFOPolicyRun.cpp vmPrism/FIFOPolicy.cpp -std=c++0x -o vmPrismRun
	./vmPrismRun
	rm -rf ./vmPrismRun
