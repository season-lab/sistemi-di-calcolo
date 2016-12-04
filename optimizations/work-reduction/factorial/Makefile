CC = gcc
CFLAGS = -O0

all:
	$(CC) $(CFLAGS) -m32 -o rec main.c recursive.c
	$(CC) $(CFLAGS) -m32 -o tail main.c tailRecursive.c
	$(CC) $(CFLAGS) -m32 -o iter main.c iterative.c
