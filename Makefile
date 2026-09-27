CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude -Wno-unused-variable
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build
DEBUG_DIR = debug_build
DEBUG = -fsanitize=address -g

SRCS = $(wildcard src/*.c)

REL_OBJ_DIR = obj/release
DEBUG_OBJ_DIR = obj/debug

REL_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(REL_OBJ_DIR)/%.o)
DEBUG_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(DEBUG_OBJ_DIR)/%.o)

PROJ_NAME = $(BUILD_DIR)/shell
DEBUG_PROJ = $(DEBUG_DIR)/debug_shell

all: $(PROJ_NAME)

run: $(PROJ_NAME)
	@echo "Running program..."
	@./$(PROJ_NAME)

debug: $(DEBUG_PROJ)
	@echo "Running debug version..."
	@gdb ./$(DEBUG_PROJ)

sanitize: $(DEBUG_PROJ)
	@echo "Running sanitized version..."
	@./$(DEBUG_PROJ)

valgrind: $(DEBUG_PROJ)
	@echo "Running valgrind version..."
	@valgrind ./$(DEBUG_PROJ)

$(DEBUG_PROJ): $(DEBUG_OBJS) | $(DEBUG_DIR)
	@$(CC) $(CFLAGS) $(DEBUG_OBJS) $(DEBUG) -o $(DEBUG_PROJ)
	@echo "Done! you can now run the sanitized version."

$(PROJ_NAME): $(REL_OBJS) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(REL_OBJS) -o $(PROJ_NAME)
	@echo "Done! you can now run the program."

$(REL_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(REL_OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(DEBUG_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEBUG_OBJ_DIR)
	@echo "Compiling debug $<..."
	@$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

$(OBJ_DIR) $(BUILD_DIR) $(DEBUG_DIR) $(REL_OBJ_DIR) $(DEBUG_OBJ_DIR):
	@echo "You don't have the $@ directory, building $@ directory..."
	@mkdir -p $@

clean:
	@echo "Cleaning Shell Files..."
	@echo "Wait a little..."
	@rm -rf $(OBJ_DIR) $(BUILD_DIR) $(DEBUG_DIR)
	@echo "Done!"

help:
	@echo "Available commands:"
	@echo "make - Build the shell"
	@echo "make run - Build AND Run the shell"
	@echo "make clean - Deletes all files for proper restart"
	@echo "make sanitize - Checks ASan for mem leak"
	@echo "make debug - Runs gdb for debugging"
	@echo "make valgrind - Runs valgrind for easier bug traces"

.PHONY: all clean run help sanitize debug
