ifeq ($(OS), Windows_NT)
	BIN := Bin\\
	DEL := del
	EXE := $(BIN)lab3.exe
else
	BIN := Bin/
	DEL := rm
	EXE := $(BIN)lab3
endif

FLAGOBJ := g++ -g -c -std=c++17 -Wall -Wextra -Wpedantic
FLAGEXE := g++ -g -std=c++17 -Wall -Wextra -Wpedantic

all: $(BIN) $(EXE)

$(EXE): $(BIN)main.o $(BIN)sorted.o $(BIN)merge.o
	$(FLAGEXE)  $(BIN)main.o  $(BIN)sorted.o  $(BIN)merge.o -o $(EXE)

$(BIN):
	-@if [ ! -d "$(BIN)" ]; then mkdir "$(BIN)"; fi

$(BIN)main.o: main.cpp sorted.hpp merge.hpp
	$(FLAGOBJ) main.cpp -o  $(BIN)main.o

$(BIN)sorted.o: sorted.cpp sorted.hpp
	$(FLAGOBJ) sorted.cpp -o  $(BIN)sorted.o

$(BIN)merge.o: merge.cpp merge.hpp
	$(FLAGOBJ) merge.cpp -o  $(BIN)merge.o

clean:
	$(DEL) $(EXE)  $(BIN)main.o  $(BIN)sorted.o  $(BIN)merge.o
