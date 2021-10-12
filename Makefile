CXX=clang++
#CXX=g++

CXXFLAGS= -g -O3 -std=c++14 
BINARIES = project1

all: clean ${BINARIES}

project1: project1.o hashtable.o
			${CXX} $^ -o $@

tests: ${BINARIES}
		./project1

clean:
	/bin/rm -f ${BINARIES} *.o 