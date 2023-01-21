/**
 * @file ch08q06-get_first_non_whitespace.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 06
 * Read input character until EOF and print the first non-whitespace character of each line.
 * @date 2023-01-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NEWLINE '\n'

/**
 * @brief Get the first non-whitespace character or EOF from user input.
 * @note Skip leading whitespaces, get the first non-whitespace character or EOF, and discard the rest of the current
 * user input line.
 * @return int First non-whitespace character or EOF.
 */
int get_first(void)
{
    int input_char;
    int first_char;

    /* Skip leading whitespaces. */
    do
    {
        input_char = getchar();
    } while (isspace(input_char));

    /* Get the first non-whitespace character or EOF. */
    first_char = input_char;

    /* Discard the rest of the current user input line. */
    while ((EOF != input_char) && (NEWLINE != (input_char = getchar())))
    {
        continue;
    }

    return first_char;
}

int main(void)
{
    int first_char;

    while (EOF != (first_char = get_first()))
    {
        printf("first non-whitespace: %c\n", first_char);
    }

    return EXIT_SUCCESS;
}
