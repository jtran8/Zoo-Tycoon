zoo: main.o menu.o inputCheck.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o 
	g++ -std=c++11 main.o menu.o inputCheck.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o -o zoo

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp
	g++ -std=c++11 -c menu.cpp

inputCheck.o: inputCheck.cpp
	g++ -std=c++11 -c inputCheck.cpp

Zoo.o: Zoo.cpp
	g++ -std=c++11 -c Zoo.cpp

Animal.o: Animal.cpp
	g++ -std=c++11 -c Animal.cpp

Tiger.o: Tiger.cpp
	g++ -std=c++11 -c Tiger.cpp

Penguin.o: Penguin.cpp
	g++ -std=c++11 -c Penguin.cpp

Turtle.o: Turtle.cpp
	g++ -std=c++11 -c Turtle.cpp

clean:
	rm *.o zoo
