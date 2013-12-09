
SRC = $(wildcard src/*.c)
CFLAGS = -std=c99 -Wall

example: example.c $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

test: test.c $(SRC)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

clean:
	rm -f example test

.PHONY: example test clean
