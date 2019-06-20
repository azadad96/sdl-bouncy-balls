output: main.o bouncyballs.o
	g++ main.o bouncyballs.o -o main -lSDL2 -lSDL2_image

main.o: main.cpp
	g++ -c main.cpp

bouncyballs.o: bouncyballs.hpp bouncyballs.cpp
	g++ -c bouncyballs.cpp

clean:
	rm *.o main
