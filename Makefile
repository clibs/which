
SRC  = $(wildcard src/*.c)
SRC += $(wildcard deps/*/*.c)
CFLAGS = -std=c99 -Wall -Ideps

example: example.c $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

test: test.c $(SRC)
	@$(CC) $(CFLAGS) $^ -o $@
	@./$@

clean:
	rm -f example test

.PHONY: example test clean
