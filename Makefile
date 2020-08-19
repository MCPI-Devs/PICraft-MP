# I am speed
CFLAGS:=-O3
INCLUDES:=-I./include

all:
	gcc -Wall -fPIC $(CFLAGS) $(INCLUDES) *.c -o pcmp.elf
