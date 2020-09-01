PREFIX = /usr
MANPREFIX = $(PREFIX)/share/man

all: main.o

%.o: %.c
	$(CC) -o $@ $< -lm

%.gz: %
	gzip $<

clean:
	rm -f *.o

test: main.o
	watch -n 0.1 ./main.o

.PHONY: all clean test
