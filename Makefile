# I am (not so) speed
CFLAGS:=-g
INCLUDES:=-I./include

all:
	gcc -Wall -fPIC $(CFLAGS) $(INCLUDES) *.c -o pcmp
