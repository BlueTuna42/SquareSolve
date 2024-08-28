#all:
#	g++ main.cpp Common.cpp Print.cpp SolveEquation.cpp UnitTests.cpp -o output

SquareSolve: common.o print.o solveEquation.o UnitTests.o main.o
	g++ -o output main.o common.o print.o solveEquation.o unitTests.o

main.o: main.cpp
	g++ -c main.cpp

Common.o: Common.cpp
	g++ -c common.cpp

Print.o: Print.cpp
	g++ -c Print.cpp

SolveEquation.o: SolveEquation.cpp
	g++ -c solveEquation.cpp

UnitTests.o: UnitTests.cpp
	g++ -c UnitTests.cpp

