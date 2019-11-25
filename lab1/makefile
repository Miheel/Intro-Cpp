all: lab1

main.o: main.cpp
	g++ -g -c -Wall -Wextra -Wpedantic main.cpp -o main.o

lab1: main.o
	g++ -g -Wall -Wextra -Wpedantic main.o -o lab1

test: lab1
	./lab1 < values.txt
clean:
	rm lab1 main.o
