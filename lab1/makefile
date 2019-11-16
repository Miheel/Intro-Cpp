all: test clean

obj: main.cpp
	g++ -c main.cpp -o main.o

exe: obj
	g++ main.o -o lab1

test: exe
	./lab1 < values.txt
clean:
	rm lab1 main.o
