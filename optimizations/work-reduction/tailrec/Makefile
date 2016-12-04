SIZE=-DM=1000000 -DN=1000
CC=gcc
CFLAGS = -m32 -fomit-frame-pointer -fno-inline-small-functions

all: tailrec

tailrec:
	$(CC) $(CFLAGS) tailrec.c -DF=sum -o tr $(SIZE) -O1
	$(CC) $(CFLAGS) tailrec.c -DF=sum_opt -o tr-opt $(SIZE) -O2
	$(CC) $(CFLAGS) tailrec.c -DF=sum_opt_man -o tr-opt-man $(SIZE) -O2

asm:
	$(CC) $(CFLAGS) tailrec.c -DF=sum -o tr.s $(SIZE) -S -O1
	$(CC) $(CFLAGS) tailrec.c -DF=sum_opt -o tr-opt.s $(SIZE) -S -O2
	$(CC) $(CFLAGS) tailrec.c -DF=sum_opt_man -o tr-opt-man.s $(SIZE) -S -O2

.phony: clean

clean:
	rm -rf tr*
