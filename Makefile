output: main.o bouncyballs.o
	g++ main.o bouncyballs.o -o main

main.o: main.cpp
	g++ -c main.cpp

bouncyballs.o: bouncyballs.hpp bouncyballs.cpp
	g++ -c main.cpp

clean:
	rm *.o main
