CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

SRCS = src/main.cpp src/Board.cpp src/Edge.cpp src/Tile.cpp src/Vertex.cpp src/Player.cpp src/KnightCard.cpp src/PromotionCard.cpp src/VictoryPointCard.cpp
HEADERS = include/Board.hpp include/Tile.hpp include/Edge.hpp include/Vertex.hpp include/Player.hpp include/Enums.hpp
TEST_SRCS = tests/Test_Board.cpp tests/TestCounter.cpp src/Board.cpp src/Edge.cpp src/Tile.cpp src/Vertex.cpp src/Player.cpp src/KnightCard.cpp src/PromotionCard.cpp src/VictoryPointCard.cpp

all: catan

catan: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o catan $(SRCS) $(LDFLAGS)

test: $(TEST_SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o test_catan $(TEST_SRCS) $(LDFLAGS)
	./test_catan

clean:
	rm -f catan test_catan
