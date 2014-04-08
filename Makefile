all: calc

calc: Driver.o Expression.o
	g++ Driver.o Expression.o -o calc

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Expression.o: Expression.cpp
	g++ -c Expression.cpp

clean:
	rm -rf *o calc
