CC=clang
ifeq (${make_debug}, true)
	CFLAGS = -Wall -std=c99 -g -O0 -DDEBUG
else
	CFLAGS = -Wall -std=c99 -O2 
endif

all:compile

test:compile
	@for f in $(wildcard test*.txt); do \
		echo "Running $$f"; \
		./day1 "$$f"; \
	done

compile:
	$(CC) $(CFLAGS) -o day1 main.c

clean:
	@rm -rf day1 day1.dSYM

.PHONY: clean test
