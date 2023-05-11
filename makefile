TARGET = main
CC = g++

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
#LIB_DIR := lib
INCLUDE_DIR := include

DEPS := $(wildcard $(INCLUDE_DIR)/*.h)
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.CPP=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS := -Wall -std=c++11 -Wextra -pedantic
LDFLAGS := -Llib
LDLIBS := -lm

.PHONY: all

all: $(TARGET) $(OBJ)

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# %.o: %.cpp
#	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(BIN_DIR)
	rm -f $(OBJ_DIR)
	rm $(EXE)
#	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

#-include $(OBJ:.o=.d)