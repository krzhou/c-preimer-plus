/**
 * @file ch08q07-payroll.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 07
 * Compute gross pay, taxes and net pay according to the pay rate and number of hours worked in a week from user input.
 * @date 2023-01-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NEWLINE '\n'

#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20
#define OVERTIME_RATE 1.5
#define HOUR_BREAK 40
#define PAY_BASE HOUR_BREAK *PAY_RATE
#define TAX_RATE1 0.15
#define PAY_BREAK1 300
#define TAX_BASE1 TAX_RATE1 *PAY_BREAK1
#define TAX_RATE2 0.20
#define PAY_BREAK2 150
#define TAX_BASE2 TAX_BASE1 + PAY_BREAK2 *TAX_RATE2
#define TAX_RATE3 0.25

/**
 * @brief Print basic pay rate options.
 */
void printOptions(void)
{
    printf("****************************************\n"
           "Enter the number corresponding to the desired pay rate or action:\n"
           "a) $%0.2f/hr\tb) $%0.2f/hr\n"
           "c) $%0.2f/hr\td) $%0.2f/hr\n"
           "q) quit\n"
           "****************************************\n",
           PAY_RATE1, PAY_RATE2, PAY_RATE3, PAY_RATE4);
}

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
    int opt = 0;     /* Option number for pay rate. */
    double hour = 0; /* #hours worked in a week */
    double grossPay = 0;
    double tax = 0;
    double PAY_RATE;

    /* Select basic pay rate. */
    printOptions();
    while (EOF != (opt = get_first()))
    {
        switch (opt)
        {
        case 'a': {
            PAY_RATE = PAY_RATE1;
            break;
        }
        case 'b': {
            PAY_RATE = PAY_RATE2;
            break;
        }
        case 'c': {
            PAY_RATE = PAY_RATE3;
            break;
        }
        case 'd': {
            PAY_RATE = PAY_RATE4;
            break;
        }
        case 'q': {
            return EXIT_SUCCESS;
        }
        default: {
            printOptions();
            continue;
        }
        }

        printf("Please input #hours worked in a week:\n");
        if (1 == scanf("%lf", &hour))
        {
            /* Compute gross pay. */
            if (0 <= hour && hour <= HOUR_BREAK)
            {
                grossPay = hour * PAY_RATE;
            }
            else if (hour > HOUR_BREAK)
            {
                grossPay = PAY_BASE + (hour - HOUR_BREAK) * PAY_RATE * OVERTIME_RATE;
            }

            /* Compute tax. */
            if (grossPay <= PAY_BREAK1)
            {
                tax = grossPay * TAX_RATE1;
            }
            else if (grossPay <= PAY_BREAK1 + PAY_BREAK2)
            {
                tax = TAX_BASE1 + (grossPay - PAY_BREAK1) * TAX_RATE2;
            }
            else
            {
                tax = TAX_BASE2 + (grossPay - PAY_BREAK1 - PAY_BREAK2) * TAX_RATE3;
            }

            /* Report. */
            printf("gross pay: %0.2lf\n"
                   "taxes: %0.2lf\n"
                   "net pay: %0.2lf\n",
                   grossPay, tax, grossPay - tax);
        }

        printOptions();
    }

    return EXIT_SUCCESS;
}
