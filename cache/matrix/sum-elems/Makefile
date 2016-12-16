CC = gcc
CFLAGS = -O1

all: matsum.c
	$(CC) $(CFLAGS) matsum.c -o matsum-by-row
	$(CC) $(CFLAGS) -DBYCOL matsum.c -o matsum-by-col

