CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp Board.cpp Edge.cpp Tile.cpp Vertex.cpp Player.cpp
HEADERS = Board.hpp Tile.hpp Edge.hpp Vertex.hpp Player.hpp Enums.hpp
TEST_SRCS = Test_Board.cpp TestCounter.cpp

all: catan

catan: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o catan $(SRCS) $(LDFLAGS)

test: $(TEST_SRCS) $(filter-out main.cpp, $(SRCS)) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o test_board Test_Board.cpp $(filter-out main.cpp, $(SRCS)) $(LDFLAGS)
	./test_board

clean:
	rm -f catan test_board test_counter
