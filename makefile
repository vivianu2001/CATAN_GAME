CXX = g++
CXXFLAGS = -std=c++11 -Wall
DEPS = ResourceType.hpp Tile.hpp Board.hpp
OBJ = main.o Board.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

catan: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f *.o catan
