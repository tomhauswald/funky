.PHONY: build run clean

BINARY  := testsuite.elf
SOURCES := \
	./*.c \
	./util/*.c

all: build run

clean:
	rm -f $(BINARY)

build: $(BINARY)

run: $(BINARY)
	./$(BINARY)

$(BINARY): $(SOURCES)
	clang-9 -std=c99 -O3 -Wall -Wextra -Werror $(^) -o $(@)