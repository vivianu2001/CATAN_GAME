CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --error-exitcode=99
TIDY = clang-tidy
TIDY_FLAGS = -checks=bugprone-*,-bugprone-narrowing-conversions,-bugprone-easily-swappable-parameters,-bugprone-exception-escape,clang-analyzer-*,performance-*,portability-*,-cppcoreguidelines-avoid-magic-numbers,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* -extra-arg=-Iinclude

SRCDIR = src
INCDIR = include
TESTDIR = tests
BUILDDIR = build

# List of source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(INCDIR)/*.hpp)
TEST_SRCS = $(wildcard $(TESTDIR)/*.cpp)

# Exclude main.cpp from the main object files
MAIN_SRCS = $(filter-out $(SRCDIR)/main.cpp, $(SRCS))
MAIN_OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(MAIN_SRCS))
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SRCS))

# Targets
TARGET = catan
TEST_TARGET = test_catan

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(MAIN_OBJS) $(BUILDDIR)/main.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

$(TEST_TARGET): $(TEST_OBJS) $(filter-out $(BUILDDIR)/main.o,$(MAIN_OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

# Pattern rule for building object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp $(HEADERS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run main program
catan: $(TARGET)

# Run tests
test: $(TEST_TARGET)

valgrind: $(TEST_TARGET)
	valgrind $(VALGRIND_FLAGS) ./$(TEST_TARGET)

tidy:
	$(TIDY) $(TIDY_FLAGS) $(SRCS) $(TEST_SRCS)

clean:
	rm -rf $(BUILDDIR) $(TARGET) $(TEST_TARGET)

.PHONY: all clean catan test valgrind tidy
