all: lab2

main.o: main.cpp
	g++ -g -c -Wall -Wextra -Wpedantic main.cpp -o main.o

lab2: main.o
	g++ -g -Wall -Wextra -Wpedantic main.o -o lab2

test: exe
	./lab2 < names.txt
clean:
	rm lab2 main.o
