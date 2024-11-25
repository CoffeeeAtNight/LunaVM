# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
LDFLAGS = -lraylib -lm -lpthread -ldl -lGL -lrt -lX11

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
PROGRAMS_DIR = programs
BIN_DIR = bin
OUTPUT_DIR = $(BIN_DIR)/$(config)

# Configurations
ifndef config
  config = Debug
endif

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: raylib $(OUTPUT_DIR)/LunaVM programs

# Build LunaVM
$(OUTPUT_DIR)/LunaVM: $(OBJS) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Ensure the output directory exists
$(OUTPUT_DIR):
	if [ ! -d "$(OUTPUT_DIR)" ]; then \
		rm -f "$(OUTPUT_DIR)"; \
		mkdir -p "$(OUTPUT_DIR)"; \
	fi

# Compile each .c file to a .o file in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Convert all .lvms files in PROGRAMS_DIR to binary format in BIN_DIR
programs: $(BIN_DIR)
	@for file in $(wildcard $(PROGRAMS_DIR)/*.lvms); do \
		bin_file=$(BIN_DIR)/$$(basename $$file .lvms).lvmb; \
		echo "Converting $$file to $$bin_file"; \
		xxd -r -p $$file > $$bin_file; \
	done

# Ensure the bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Build raylib
raylib:
	@echo "==== Building raylib ===="
	@if [ ! -d raylib ]; then git clone https://github.com/raysan5/raylib.git; fi
	@cd raylib/src && make && sudo make install

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean programs raylib

