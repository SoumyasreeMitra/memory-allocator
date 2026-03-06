CC=gcc
CFLAGS=-Wall -g

all: test

test:
	$(CC) $(CFLAGS) src/allocator.c tests/test_allocator.c -o allocator_test

run:
	./allocator_test

clean:
	rm -f allocator_test