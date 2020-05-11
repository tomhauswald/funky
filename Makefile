CC := clang-11
CC_FLAGS := -std=c11 -O3

TESTSUITE_BINARY := testsuite.elf
TESTSUITE_SOURCE := tests.c

.PHONY: all test

all: $(TESTSUITE_BINARY)

test: $(TESTSUITE_BINARY)
	./$(<)

$(TESTSUITE_BINARY): $(TESTSUITE_SOURCE) $(MAKEFILE_LIST)
	$(CC) $(CC_FLAGS) -o $(@) $(<)
