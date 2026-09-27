CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build


SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=obj/%.o)

PROJ_NAME = $(BUILD_DIR)/shell

all: $(PROJ_NAME)

run: $(PROJ_NAME) | $(BUILD_DIR)
	@echo "Running program..."                                 @./$(PROJ_NAME)

$(PROJ_NAME): $(OBJS) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(PROJ_NAME)
	@echo "Done! you can now run the program."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Linking Program..."                                 @$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BUILD_DIR):
	@echo "You don't have the $@ directory, building $@ directory..."
	@mkdir -p $@

clean:
	@echo "Cleaning Shell Files..."
	@echo "Wait a little..."
	@rm -rf $(OBJ_DIR) $(PROJ_NAME) $(BUILD_DIR)
	@echo "Done!"

help:
	@echo "Available commands:"
	@echo "make - Build the shell"
	@echo "make run - Run the shell"
	@echo "make clean - Deletes all files for proper restart"

.PHONY: all clean run help
