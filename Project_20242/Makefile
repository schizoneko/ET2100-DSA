# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = src/obj
EXEC = main

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/data/data_process.c $(OBJ_DIR)/students.c $(OBJ_DIR)/subjects.c $(OBJ_DIR)/teachers.c

# Include directories
INCLUDES = -I$(INC_DIR)

# Object files
OBJS = $(SRCS:.c=.o)

# Final target: executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Rule to compile each source file into object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(OBJ_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)
