# Define variables
CC = gcc
CFLAGS = -Wall -g
TARGET = main
SRCS = main.c isEven.c isOdd.c
OBJS = $(SRCS:.c=.o)

# Default rule to build the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the the built files from make
clean:
	rm -f $(TARGET) $(OBJS)