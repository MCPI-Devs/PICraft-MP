CFLAGS:=-ansi -I./

all:
	gcc $(CFLAGS) ./*.c utils/*.c
