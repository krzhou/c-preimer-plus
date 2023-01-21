/**
 * @file ch08q04-average_word_letter_count.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 04
 * Read input characters until EOF and calculate average letter count of words.
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int input_char;
    unsigned long long letter_count = 0;
    unsigned long long word_count = 0;
    unsigned long long word_letter_count = 0;
    double average_word_letter_count = 0;

    while (EOF != (input_char = getchar()))
    {
        if (!isspace(input_char) && !ispunct(input_char))
        {
            /* input character is a "letter" */
            word_letter_count++;
        }
        else
        {
            if (0 < word_letter_count)
            {
                /* reach end of word */
                word_count++;

                /* reset word letter count for the next word */
                letter_count += word_letter_count;
                word_letter_count = 0;
            }
        }
    }

    average_word_letter_count = (double)letter_count / (double)word_count;
    printf("average letter count in each word: %f\n", average_word_letter_count);

    return EXIT_SUCCESS;
}
