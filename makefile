CC=gcc
CFLAGS=-Wall -Wextra -Iinclude

all: sysinfo

sysinfo: src/main.c
	$(CC) $(CFLAGS) -o sysinfo src/*.c -lm

clean:
	rm -f sysinfo