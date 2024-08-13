CC = clang
CFLAGS = -Wall -g
BIN = bin
SRC = $(wildcard src/*.c)

main:
	mkdir -p bin
	$(CC) $(SRC) -o $(BIN)/main 

