CXXFLAGS = -g -Wall

all: main.o funcs.o
	g++ $(CXXFLAGS) -o main main.o funcs.o

main: main.o funcs.o
	g++ $(CXXFLAGS) -o main main.o funcs.o

tests: tests.o funcs.o
	g++ $(CXXFLAGS) -o tests tests.o funcs.o



funcs.o: funcs.cpp funcs.h time.h

main.o: main.cpp funcs.h

tests.o: tests.cpp doctest.h funcs.h

clean:
	rm -f *.o
