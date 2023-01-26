/**
 * @file ch08q08-calculator.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 08
 * Simple calculator support addition, subtraction, multiplication and division between 2 operands.
 * @date 2023-01-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NEWLINE '\n'

#define SUCCESS 0
#define FAILURE -1

#define USER_INPUT_BUFFER_SIZE 32

typedef float operand_t;

void print_options(void)
{
    printf("Enter the operation of your choice:\n"
           "a. add \t s. subtract\n"
           "m. multiply \t d. divide\n"
           "q. quit\n");
}

/**
 * @brief Get the first non-whitespace character or EOF from user input.
 * @note Skip leading whitespaces, get the first non-whitespace character or EOF, and discard the rest of the current
 * user input line.
 * @return First non-whitespace character or EOF.
 */
int get_first_non_whitespace_char(void)
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

/**
 * @brief Get the first non-whitespace string from user input.
 * 
 * @param[out] str The first non-whitespace string from user input.
 * @warning Caller is responsible to allocate enough space for string buffer str.
 * @return FAILURE when reaching the end of user input; SUCCESS otherwise.
 */
int get_first_non_whitespace_str(char* str)
{
    int return_code = SUCCESS;
    int user_input_char;

    /* Get a user input string. */
    return_code = scanf("%s", str);
    if (EOF == return_code)
    {
        /* Reach the end of user input. */
        return_code = FAILURE;
    }

    /* Discard the rest of user input line. */
    while ((EOF != (user_input_char = getchar())) && (NEWLINE != user_input_char))
    {
        continue;
    }

    return return_code;
}

/**
 * @brief Get an one-character option from user input.
 * 
 * @param[out] option One-character option.
 * @return SUCCESS when getting a non-whitespace character as option from user input; FAILURE otherwise.
 */
int get_option(int *option)
{
    print_options();
    *option = get_first_non_whitespace_char();
    if (EOF != *option)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/**
 * @brief Get the first operand from user input.
 * 
 * @param operand Float operand.
 * @return SUCCESS when getting a valid float number from user input; FAILURE otherwise.
 */
int get_first_operand(operand_t *operand)
{
    int return_code;
    char user_input[USER_INPUT_BUFFER_SIZE];

    printf("Enter first number: ");
    do
    {
        /* Get a user input string. */
        return_code = get_first_non_whitespace_str(user_input);
        if (FAILURE == return_code)
        {
            return_code = FAILURE;
            break;
        }

        if (1 == return_code)
        {
            /* Get non-whitespace user input. */

            /* Parse user input as a float. */
            return_code = sscanf(user_input, "%f", operand);
            if (1 == return_code)
            {
                /* Get a valid float from user input. */
                return_code = SUCCESS;
                break;
            }
            else if (EOF == return_code)
            {
                /* Reach the end of user input. */
                return_code = FAILURE;
                break;
            }
            else
            {
                /* User input is not a valid float. */
                printf("%s is not a number.\n"
                       "Please enter a number, such as 2.5, -1.78E8, or 3: ",
                       user_input);
            }
        }
    } while (true);

    return return_code;
}

int get_second_operand(operand_t *operand)
{
    int return_code;
    char user_input[USER_INPUT_BUFFER_SIZE];

    printf("Enter second number: ");
    do
    {
        /* Get a user input string. */
        return_code = get_first_non_whitespace_str(user_input);
        if (FAILURE == return_code)
        {
            return_code = FAILURE;
            break;
        }

        if (1 == return_code)
        {
            /* Get non-whitespace user input. */

            /* Parse user input as a float. */
            return_code = sscanf(user_input, "%f", operand);
            if (1 == return_code)
            {
                /* Get a valid float from user input. */
                return_code = SUCCESS;
                break;
            }
            else if (EOF == return_code)
            {
                /* Reach the end of user input. */
                return_code = FAILURE;
                break;
            }
            else
            {
                /* User input is not a valid float. */
                printf("%s is not a number.\n"
                       "Please enter a number, such as 2.5, -1.78E8, or 3: ",
                       user_input);
            }
        }
    } while (true);

    return return_code;
}

int get_second_non_zero_operand(operand_t *operand)
{
    int return_code;
    char user_input[USER_INPUT_BUFFER_SIZE];

    printf("Enter second number: ");
    do
    {
        /* Get a user input string. */
        return_code = get_first_non_whitespace_str(user_input);
        if (FAILURE == return_code)
        {
            return_code = FAILURE;
            break;
        }

        if (1 == return_code)
        {
            /* Get non-whitespace user input. */

            /* Parse user input as a float. */
            return_code = sscanf(user_input, "%f", operand);
            if (1 == return_code)
            {
                if (0 != *operand)
                {
                    /* Get a valid float from user input. */
                    return_code = SUCCESS;
                    break;
                }
                else
                {
                    printf("Enter a number other than 0: ");
                }
            }
            else if (EOF == return_code)
            {
                /* Reach the end of user input. */
                return_code = FAILURE;
                break;
            }
            else
            {
                /* User input is not a valid float. */
                printf("%s is not a number.\n"
                       "Please enter a number, such as 2.5, -1.78E8, or 3: ",
                       user_input);
            }
        }
    } while (true);

    return return_code;
}

int handle_add(void)
{
    operand_t operand1;
    operand_t operand2;
    int return_code = SUCCESS;

    if ((SUCCESS == get_first_operand(&operand1)) && (SUCCESS == get_second_operand(&operand2)))
    {
        printf("%g + %g = %g\n", operand1, operand2, operand1 + operand2);
    }
    else
    {
        return_code = FAILURE;
    }
    return return_code;
}

int handle_sub(void)
{
    operand_t operand1;
    operand_t operand2;
    int return_code = SUCCESS;

    if ((SUCCESS == get_first_operand(&operand1)) && (SUCCESS == get_second_operand(&operand2)))
    {
        printf("%g - %g = %g\n", operand1, operand2, operand1 - operand2);
    }
    else
    {
        return_code = FAILURE;
    }
    return return_code;
}

int handle_mul(void)
{
    operand_t operand1;
    operand_t operand2;
    int return_code = SUCCESS;

    if ((SUCCESS == get_first_operand(&operand1)) && (SUCCESS == get_second_operand(&operand2)))
    {
        printf("%g * %g = %g\n", operand1, operand2, operand1 * operand2);
    }
    else
    {
        return_code = FAILURE;
    }
    return return_code;
}

int handle_div(void)
{
    operand_t operand1;
    operand_t operand2;
    int return_code = SUCCESS;

    if ((SUCCESS == get_first_operand(&operand1)) && (SUCCESS == get_second_non_zero_operand(&operand2)))
    {
        printf("%g / %g = %g\n", operand1, operand2, operand1 / operand2);
    }
    else
    {
        return_code = FAILURE;
    }
    return return_code;
}

int main(void)
{
    bool endloop = false;
    int option;
    int return_code;

    do
    {
        return_code = get_option(&option);
        if (SUCCESS != return_code)
        {
            /* Unable to get option from user input. */
            break;
        }

        switch (option)
        {
        case 'a': {
            endloop = (SUCCESS != handle_add());
            break;
        }
        case 's': {
            endloop = (SUCCESS != handle_sub());
            break;
        }
        case 'm': {
            endloop = (SUCCESS != handle_mul());
            break;
        }
        case 'd': {
            endloop = (SUCCESS != handle_div());
            break;
        }
        case 'q': {
            printf("Bye.\n");
            endloop = true;
            break;
        }
        default: {
            printf("Invalid operation.\n");
            endloop = true;
        }
        }

    } while (!endloop);

    return EXIT_SUCCESS;
}
