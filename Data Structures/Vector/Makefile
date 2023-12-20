# Variables
CC = g++
AR = ar
CFLAGS = -Wall -Wextra -std=c++11
LIB_NAME = libvector.a
SRC = vector.cc
OBJ = $(SRC:.cc=.o)
TAR_NAME = vector.tar.gz

# Default target
all: $(LIB_NAME)

# Rule to create object file
%.o: %.cc
	$(CC) -c $(CFLAGS) $< -o $@

# Rule to create library file
$(LIB_NAME): $(OBJ)
	$(AR) rvs $(LIB_NAME) $(OBJ)

# Rule to create tar file
tar:
	tar -czvf $(TAR_NAME) *.cc *.h Makefile

# Rule to clean
clean:
	rm -f $(OBJ) $(LIB_NAME) $(TAR_NAME)

.PHONY: all tar clean