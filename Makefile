# Compiler
CC = g++

# Compiler Flags
CFLAGS = -Wall -std=c++11

# Output Binary Name
BIN = library_system

# Source Files
SRCS = main.cpp Book.cpp Member.cpp Person.cpp Librarian.cpp InputHandle.cpp Date.cpp fileread.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Build the program
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# Clean up
clean:
	rm -f $(BIN) $(OBJS)

