CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp Board.cpp Edge.cpp Tile.cpp Vertex.cpp Player.cpp
HEADERS = Board.hpp Tile.hpp Edge.hpp Vertex.hpp Player.hpp

all: catan

catan: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o catan $(SRCS) $(LDFLAGS)

clean:
	rm -f catan
