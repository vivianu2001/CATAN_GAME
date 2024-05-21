CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: catan

catan: main.o Board.o Tile.o
	$(CXX) $(CXXFLAGS) -o catan main.o Board.o Tile.o $(LDFLAGS)

main.o: main.cpp Board.hpp Tile.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Board.o: Board.cpp Board.hpp Tile.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

Tile.o: Tile.cpp Tile.hpp
	$(CXX) $(CXXFLAGS) -c Tile.cpp

clean:
	rm -f *.o catan
