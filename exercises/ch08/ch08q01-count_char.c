/**
 * @file ch08q01-count_char.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 01
 * Counts the number of characters in the input up to the end of file.
 * @date 2023-01-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned long long char_count = 0;

    while (EOF != getchar())
    {
        char_count++;
    }
    printf("%llu\n", char_count);

    return EXIT_SUCCESS;
}
