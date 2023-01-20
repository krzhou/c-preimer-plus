/**
 * @file print_ascii_128.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Print characters of ASCII 0 through 256.
 * @date 2023-01-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 256; i++)
    {
        putchar(i);
    }
    return 0;
}
