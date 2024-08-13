CC = clang
CFLAGS = -Wall -g
BIN = bin

SRC = $(wildcard src/*.c)
SDL_FLAGS = -I/usr/local/include -L/usr/local/lib -lSDL2

main:
	mkdir -p bin
	$(CC) $(SRC) $(SDL_FLAGS) -o $(BIN)/main.exe 

