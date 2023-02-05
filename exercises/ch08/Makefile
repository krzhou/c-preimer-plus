# C compilor options.
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic $(IFLAGS)
IFLAGS =
LFLAGS =
LDFLAGS =

# Executables to build.
EXECUTABLES = ch08q01-count_char \
              ch08q02-echo_char_and_ascii \
              print_ascii_128 \
              print_ascii_256 \
              ch08q03-count_uppercase_and_lowercase \
              ch08q04-average_word_letter_count \
              ch08q05-binary_guess \
              ch08q06-get_first_non_whitespace \
              ch08q07-payroll \
              ch08q08-calculator

# Default target.
all: $(EXECUTABLES)

clean:
	rm -rf $(EXECUTABLES) *.o *.dSYM

.PHONY: all clean

# Linker step.
ch08q01-count_char: ch08q01-count_char.o
	$(CC) $(CFLAGS) -o $@ $^

ch08q02-echo_char_and_ascii: ch08q02-echo_char_and_ascii.o
	$(CC) $(CFLAGS) -o $@ $^

# test facilities for ch08q02-echo_char_and_ascii
print_ascii_128: print_ascii_128.o
	$(CC) $(CFLAGS) -o $@ $^

# test facilities for ch08q02-echo_char_and_ascii
print_ascii_256: print_ascii_256.o
	$(CC) $(CFLAGS) -o $@ $^

ch08q03-count_uppercase_and_lowercase: ch08q03-count_uppercase_and_lowercase.o
	$(CC) $(CFLAGS) -o $@ $^

ch08q04-average_word_letter_count: ch08q04-average_word_letter_count.o
	$(CC) $(CFLAGS) -o $@ $^

ch08q05-binary_guess: ch08q05-binary_guess.o
	$(CC) $(CFLAGS) -o $@ $^

ch08q06-get_first_non_whitespace: ch08q06-get_first_non_whitespace.o
	$(CC) $(CFLAGS) -o $@ $^

ch08q07-payroll: ch08q07-payroll.o
	$(CC) $(CFLAGS) -o $@ $^

ch08q08-calculator: ch08q08-calculator.o
	$(CC) $(CFLAGS) -o $@ $^

# Compile .o using the corresponding .c.
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
