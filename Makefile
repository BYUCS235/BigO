CFLAGS=-std=c++11 -g

all: efficiency

efficiency: efficiency.cpp
	g++ $(CFLAGS) efficiency.cpp -o efficiency
	
