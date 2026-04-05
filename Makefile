CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2

SRC = src/array.c src/linked_list.c src/bst.c src/avl.c src/graph.c src/utils.c src/tests.c
OUT = tests

all: $(OUT)

$(OUT): $(SRC)
	gcc $(CFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)

Command to build:
