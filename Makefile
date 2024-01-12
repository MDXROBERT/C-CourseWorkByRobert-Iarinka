CC = g++
CFLAGS = -Wall -std=c++11
BIN_DIR = bin
SRC_DIR = source
HEADER_DIR = header
TEST_DIR = tests
CATCH = $(HEADER_DIR)/catch.hpp

# Executable names
MAIN_BIN = $(BIN_DIR)/library_system
TEST_BIN = $(BIN_DIR)/test_suite

# Source files - Include all .cpp files from source directory
MAIN_SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Exclude the tests.cpp file from the main application build
MAIN_SRCS_NO_TESTS = $(filter-out $(SRC_DIR)/tests.cpp, $(MAIN_SRCS))

# Object files for the main application
MAIN_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(MAIN_SRCS_NO_TESTS))

# Source files - Include all .cpp files from test directory
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

# Object files for the test suite
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%.o,$(TEST_SRCS)) 
TEST_OBJS += $(filter-out $(BIN_DIR)/main.o, $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(MAIN_SRCS)))

# Default target
all: $(MAIN_BIN)

# Link the main program
$(MAIN_BIN): $(MAIN_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Link the test program
$(TEST_BIN): $(TEST_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

# Compile test source files into object files
$(BIN_DIR)/%.o: $(TEST_DIR)/%.cpp $(CATCH)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

# Test target to build and run the test suite
test: $(TEST_BIN)
	./$(TEST_BIN)

# Clean target
clean:
	@rm -rf $(BIN_DIR)

.PHONY: all test clean
