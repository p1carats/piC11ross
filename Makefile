CC=gcc
CFLAGS=-I. -g3 -Wall -W
Name=picross.exe
SRC_DIR=./src
OBJ_DIR=./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(Name)

$(Name): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -r ./obj

fclean: clean
	rm -f $(Name)
