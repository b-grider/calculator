all: calc

calc: Driver.o Expression.o Number.o Fraction.o
	g++ Driver.o Expression.o Number.o Fraction.o -o calc

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Expression.o: Expression.cpp
	g++ -c Expression.cpp
	
Number.o: Number.cpp
	g++ -c Number.cpp
	
Fraction.o: Fraction.cpp
	g++ -c Fraction.cpp

clean:
	rm -rf *o calc
