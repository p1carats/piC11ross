CC=gcc
CFLAGS=-I. -g3 -Wall -W

BUILD_TARGET ?= picross.exe
BUILD_DIR ?= ./build
SRC_DIR ?= ./src

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(OBJ_FILES:.o=.d)

TESTS_TARGET ?= test.out
TESTS_DIR ?= ./tests
TESTS_SRC_FILES := $(shell find $(TESTS_DIR) -name *.c)
TESTS_OBJ_FILES := $(patsubst $(TESTS_DIR)/%.c,$(BUILD_DIR)/%.o,$(TESTS_SRC_FILES))
TESTS_DEP_FILES := $(TESTS_OBJ_FILES:.o=.d)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(TESTS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/$(BUILD_TARGET): $(OBJ_FILES)
	$(CC) $(OBJS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/$(TESTS_TARGET): $(TESTS_OBJ_FILES)
	$(CC) $(OBJS) $(LDFLAGS) -o $@ $^

.PHONY: all test clean

all: $(BUILD_DIR)/$(BUILD_TARGET)

test: $(BUILD_DIR)/$(TESTS_TARGET)

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEP_FILES)