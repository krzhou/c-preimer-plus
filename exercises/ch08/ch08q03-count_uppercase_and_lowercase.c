/**
 * @file ch08q03-count_uppercase_and_lowercase.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 03
 * Read input characters until EOF and count uppercase and lowercase letters and others.
 * @date 2023-01-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int input_char;
    unsigned long long lowercase_letter_count = 0;
    unsigned long long uppercase_letter_count = 0;
    unsigned long long other_char_count = 0;

    while (EOF != (input_char = getchar()))
    {
        if (islower(input_char))
        {
            lowercase_letter_count++;
        }
        else if (isupper(input_char))
        {
            uppercase_letter_count++;
        }
        else
        {
            other_char_count++;
        }
    }

    printf("lowercase letter count:\t%llu\n"
           "uppercase letter count:\t%llu\n"
           "other characters count:\t%llu\n",
           lowercase_letter_count, uppercase_letter_count, other_char_count);

    return EXIT_SUCCESS;
}
