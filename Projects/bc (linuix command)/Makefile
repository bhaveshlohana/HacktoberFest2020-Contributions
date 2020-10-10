project: main.o functions.o stack.o cstack.o solvestring.o
	cc main.o functions.o stack.o cstack.o solvestring.o -o  project -lm
main.o: main.c functions.c solvestring.c
	cc -Wall -c main.c solvestring.c functions.c 
solvestring.o : stack.c cstack.c
	cc -Wall -c stack.c cstack.c
