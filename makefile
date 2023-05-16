TARGET := main

CC = g++

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
LIB_DIR := lib

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
# LIB := $(wildcard $(LIB_DIR)/*.hpp)
# CLIB := 

LDFLAGS := -Llib
CFLAGS := -Wall -Wextra -std=c++11
CPPFLAGS := -Iinclude -MMD -MP
LDLIBS   := -lm

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR) main.exe