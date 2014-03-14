all: test.cc
	clang++ -g -std=c++11 test.cc 
r: all
	./a.out

