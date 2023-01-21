/**
 * @file ch08q05-binary_guess.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 05
 * Guess a number, which the user picked, between 1 to 100 using binary search.
 * @date 2023-01-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_GUESS 1
#define MAX_GUESS 100
#define INITIAL_GUESS 50
#define NEWLINE '\n'

/**
 * @brief Get user input.
 * @note Skip the leading empty lines, get the first character that is not a newline and discard the rest of the user
 * input line.
 * @return int The first character in the user input line.
 */
int get_user_input(void)
{
    int input_char;
    int first_char;

    /* Skip leading newlines. */
    while (NEWLINE == (input_char = getchar()))
    {
        continue;
    }

    /* Get the first character that is not a newline. */
    first_char = input_char;

    /* Discard the rest of the line. */
    while ((EOF != input_char) && (NEWLINE != (input_char = getchar())))
    {
        continue;
    }

    return first_char;
}

int main(void)
{
    int user_input;
    int guess = INITIAL_GUESS;
    int upper_bound = MAX_GUESS; /* upper bound of the possible answer */
    int lower_bound = MIN_GUESS; /* lower bound of the possible answer */
    bool guess_hit = false;      /* whether the current guess is correct */
    bool stop = false;           /* whether user stops playing */

    printf("Pick an integer from %d to %d. I will try to guess it.\n"
           "Respond with c for correct, h for too high and l for too low.\n",
           MIN_GUESS, MAX_GUESS);

    while (!guess_hit && (lower_bound <= upper_bound) && !stop)
    {
        printf("Is your number %d?\n", guess);
        user_input = get_user_input();
        switch (user_input)
        {
        case 'c': {
            /* Guess is correct. */
            guess_hit = true;
            break;
        }
        case 'h': {
            /* Guess is too high. */
            upper_bound = guess - 1;
            guess = lower_bound + (upper_bound - lower_bound) / 2;
            break;
        }
        case 'l': {
            /* Guess is too low. */
            lower_bound = guess + 1;
            guess = lower_bound + (upper_bound - lower_bound) / 2;
            break;
        }
        case EOF: {
            /* User stops playing. */
            stop = true;
            break;
        }
        default: {
            printf("Respond with c for correct, h for too high and l for too low.\n");
        }
        }
    }

    if (stop)
    {
        printf("Stop guessing.\n");
    }
    else if (guess_hit)
    {
        printf("Gotcha!\n");
    }
    else
    {
        printf("You got me. I cannot guess your number.\n");
    }

    return EXIT_SUCCESS;
}
