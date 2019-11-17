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
	./$(EXE)

$(EXE): main sorted merge
	$(FLAGEXE) main.o sorted.o merge.o -o lab3

main: main.cpp sorted.hpp merge.hpp
	$(FLAGOBJ) main.cpp -o main.o

sorted: sorted.cpp sorted.hpp
	$(FLAGOBJ) sorted.cpp -o sorted.o

merge: merge.cpp merge.hpp
	$(FLAGOBJ) merge.cpp -o merge.o

clean:
	$(DEL) $(EXE) main.o sorted.o merge.o
