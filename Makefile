# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = -Wall -Wextra -O2

# Define the target executable name
TARGET = assignment

# Define the source files
SRC = assignment.c

# Source files for the test program
TEST_SRC = test.c

# Rule to build the target executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	
# Build the test exe
#test: $(TARGET) $(TEST_SRC)
#	$(CC) $(CFLAGS) -o test $(TEST_SRC)

# Run tests
test: $(TARGET) test.c
	$(CC) $(CFLAGS) -o test test.c
	./$(TARGET) 5 10
	./test

# Clean up the build files
clean:
	rm -f $(TARGET) test
