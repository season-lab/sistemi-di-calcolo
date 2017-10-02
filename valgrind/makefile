SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
CFLAGS = -m32 -g #-Wall
CC = gcc
all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean: 
	rm -f $(PROGS)
