CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

SRCDIR = src
INCDIR = include
TESTDIR = tests
BUILDDIR = build

# List of source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(INCDIR)/*.hpp)
TEST_SRCS = $(wildcard $(TESTDIR)/*.cpp)

# Exclude main.cpp from the main object files
MAIN_OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(filter-out $(SRCDIR)/main.cpp,$(SRCS)))
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SRCS))

# Targets
TARGET = catan
TEST_TARGET = test_catan

all: $(TARGET)

$(TARGET): $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS) $(filter-out $(BUILDDIR)/main.o,$(MAIN_OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^

# Pattern rule for building object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(TEST_TARGET)
