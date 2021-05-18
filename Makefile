CC=gcc
CFLAGS=-I. -g3 -Wall -W

BUILD_TARGET ?= picross.exe
BUILD_DIR ?= ./build
SRC_DIR ?= ./src

SRC_FILES := $(shell find $(SRC_DIR) -name *.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(OBJS:.o=.d)

TEST_TARGET = test
TEST_FLAGS = $(LFLAGS) -lcriterion --coverage

$(BUILD_DIR)/$(BUILD_TARGET): $(OBJ_FILES)
	$(CC) $(OBJS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEP_FILES)