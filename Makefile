run: main
	./main

compile: main.cpp run
	g++ -Wall -g main.cpp -o main
	run

