CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp Player.cpp Catan.cpp Board.cpp Tile.cpp
HEADERS = Player.hpp Catan.hpp Board.hpp Tile.hpp Resource.hpp

all: catan

catan: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o catan $(SRCS) $(LDFLAGS)

clean:
	rm -f catan
