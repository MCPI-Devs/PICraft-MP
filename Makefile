# I am speed
INCLUDES:=-I./include

all:
	#gcc -Wall -fPIC $(CFLAGS) $(INCLUDES) *.c -o pcmp.elf
	gcc -Wall -fPIC $(INCLUDES) server.c -o pcmp.elf
