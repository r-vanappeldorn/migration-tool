CC = gcc
CFLAGS = -Wall -Wextra -Iproject/include

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = build/app

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(BIN)
