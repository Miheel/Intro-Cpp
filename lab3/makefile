ifeq ($(OS), Windows_NT)
	DEL := del
	EXE := lab3.exe
else
	DEL := rm
	EXE := lab3
endif

FLAGOBJ := g++ -g -c -std=c++17
FLAGEXE := g++ -g -std=c++17

all: $(EXE)

$(EXE): main sorted
	$(FLAGEXE) main.o sorted.o -o lab3

main: main.cpp sorted.hpp
	$(FLAGOBJ) main.cpp -o main.o

sorted: sorted.cpp sorted.hpp
	$(FLAGOBJ) sorted.cpp -o sorted.o

clean:
	$(DEL) $(EXE) main.o sorted.o
