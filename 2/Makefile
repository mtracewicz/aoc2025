CC=clang
ifeq (${make_debug}, true)
	CFLAGS = -Wall -std=c99 -g -O0 -DDEBUG
else
	CFLAGS = -Wall -std=c99 -O2 
endif

all:part1 part2

test:test1 test2

test1:part1
	@echo "Part 1:"
	@for f in $(wildcard test*.txt); do \
		echo "\tRunning $$f"; \
		./part_1 "$$f"; \
	done

test2:part2
	@echo "Part 2:"
	@for f in $(wildcard test*.txt); do \
		echo "\tRunning $$f"; \
		./part_2 "$$f"; \
	done

part1:
	$(CC) $(CFLAGS) -o part_1 part_1.c

part2:
	$(CC) $(CFLAGS) -o part_2 part_2.c

clean:
	@rm -rf part_1 part_1.dSYM part_2 part_2.dSYM

.PHONY: clean test
