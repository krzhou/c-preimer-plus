# C compilor options.
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic $(IFLAGS)
IFLAGS =
LFLAGS =
LDFLAGS =

# Executables to build.
EXECUTABLES = ch09q01-min_double

# Default target.
all: $(EXECUTABLES)

clean:
	rm -rf $(EXECUTABLES) *.o *.dSYM

.PHONY: all clean

# Linker step.
ch09q01-min_double: ch09q01-min_double.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile .o using the corresponding .c.
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
