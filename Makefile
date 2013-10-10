
example: example.c src/which.c
	$(CC) -std=c99 $^ -o $@

.PHONY: example