# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
PROGRAMS_DIR = programs
BIN_DIR = bin

# Target executable
TARGET = lunavm

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET) programs

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c file to a .o file in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Convert all .txt files in PROGRAMS_DIR to binary format in BIN_DIR
programs: $(BIN_DIR)
	@for file in $(wildcard $(PROGRAMS_DIR)/*.lvms); do \
		bin_file=$(BIN_DIR)/$$(basename $$file .lvms).lvmb; \
		echo "Converting $$file to $$bin_file"; \
		xxd -r -p $$file > $$bin_file; \
	done

# Ensure the bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(BIN_DIR)

# Phony targets
.PHONY: all clean programs

