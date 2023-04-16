/**
 * @file ch09q01-min_double.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief function min() that returns the smaller of 2 double values.
 * @version 0.1
 * @date 2023-04-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>

double min(double para1, double para2)
{
    if (para1 < para2)
    {
        return para1;
    }
    return para2;
}

int main(void)
{
    double val1 = 0.0;
    double val2 = 0.0;

    while (true)
    {
        printf("Input 2 double values to get the smaller; input q to exit: ");
        if (2 == scanf("%lf %lf", &val2, &val2))
        {
            printf("Smaller value between %lf and %lf is %lf.\n", val1, val2, min(val1, val2));
        }
        else
        {
            break;
        }
    }
    return EXIT_FAILURE;
}
