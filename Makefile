# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lraylib -lm

# Directories
SRC_DIR = .
UTILS_DIR = utils
BUILD_DIR = build

# Source files
MAIN_SRC = $(SRC_DIR)/main.c
UTILS_SRC = $(wildcard $(UTILS_DIR)/*.c)

# Object files
MAIN_OBJ = $(BUILD_DIR)/main.o
UTILS_OBJ = $(UTILS_SRC:$(UTILS_DIR)/%.c=$(BUILD_DIR)/%.o)

# Target executable
TARGET = main

# Default target
all: $(BUILD_DIR) $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link main executable
$(TARGET): $(MAIN_OBJ) $(UTILS_OBJ)
	$(CC) -o $@ $^ $(LIBS)

# Compile main source
$(BUILD_DIR)/main.o: $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile utils sources
$(BUILD_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean rebuild run
