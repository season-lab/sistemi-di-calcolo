CFLAGS = -m32 -fomit-frame-pointer -fno-inline-small-functions
LFLAGS = -lm

all: algeb.c
	gcc $(CFLAGS) -O0 -o al-O0 algeb.c $(LFLAGS)
	gcc $(CFLAGS) -O1 -o al-O1 algeb.c $(LFLAGS)
	gcc $(CFLAGS) -O2 -o al-O2 algeb.c $(LFLAGS)
	gcc $(CFLAGS) -O0 -o al-opt-O0 algeb.c -D OPT $(LFLAGS)
	gcc $(CFLAGS) -O1 -o al-opt-O1 algeb.c -D OPT $(LFLAGS)
	gcc $(CFLAGS) -O2 -o al-opt-O2 algeb.c -D OPT $(LFLAGS)

asm:
	gcc $(CFLAGS) -O0 -S -o al-O0.s algeb.c $(LFLAGS)
	gcc $(CFLAGS) -O1 -S -o al-O1.s algeb.c $(LFLAGS)
	gcc $(CFLAGS) -O2 -S -o al-O2.s algeb.c $(LFLAGS)
	gcc $(CFLAGS) -O0 -S -o al-opt-O0.s algeb.c -D OPT $(LFLAGS)
	gcc $(CFLAGS) -O1 -S -o al-opt-O1.s algeb.c -D OPT $(LFLAGS)
	gcc $(CFLAGS) -O2 -S -o al-opt-O2.s algeb.c -D OPT $(LFLAGS)

.phony: clean

clean:
	rm -rf al-*
