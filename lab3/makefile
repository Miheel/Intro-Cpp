INCLUDE := include/
FLAGOBJ := g++ -g -c -std=c++17
FLAGEXE := g++ -g -std=c++17

all: prog

prog: main sorted
	$(FLAGEXE) main.o sorted.o -o lab3

main: main.cpp $(INCLUDE)sorted.hpp
	$(FLAGOBJ) main.cpp -I$(INCLUDE) -o main.o

sorted: sorted.cpp $(INCLUDE)sorted.hpp
	$(FLAGOBJ) sorted.cpp -I$(INCLUDE) -o sorted.o


