
CC = g++


CFLAGS = -Wall -std=c++11


BIN = library_system


TEST_BIN = tests


SRCS = main.cpp Book.cpp Member.cpp Person.cpp Librarian.cpp InputHandle.cpp Date.cpp fileread.cpp


TEST_SRCS = tests.cpp Book.cpp Member.cpp Person.cpp Librarian.cpp InputHandle.cpp Date.cpp fileread.cpp


OBJS = $(SRCS:.cpp=.o)


TEST_OBJS = $(TEST_SRCS:.cpp=.o)


CATCH = catch.hpp


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)


test: $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_BIN) $(TEST_OBJS) && ./$(TEST_BIN)


%.o: %.cpp $(CATCH)
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(BIN) $(OBJS) $(TEST_BIN) $(TEST_OBJS)
