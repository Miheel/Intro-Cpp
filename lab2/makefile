all: test clean

obj: main.cpp
	g++ -c main.cpp -o main.o

exe: obj
	g++ main.o -o lab2

test: exe
	./lab2 < names.txt
clean:
	rm lab2 main.o
