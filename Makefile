PREFIX = /usr
MANPREFIX = $(PREFIX)/share/man

all: main.o

%.o: %.c
	$(CC) -o $@ $<

%.gz: %
	gzip $<

clean:
	rm -f *.o

test: main.o
	./main.o

.PHONY: all clean test
