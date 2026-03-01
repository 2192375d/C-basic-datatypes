CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -O2

SRC := array.c linkedList.c bst.c avl.c graph.c utils.c tests.c
OUT := tests

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)

Command to build:
