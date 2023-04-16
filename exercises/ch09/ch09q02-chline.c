/**
 * @file ch09q02-chline.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief function chline(ch, i, j) that prints the requested character in columns i though j
 * @version 0.1
 * @date 2023-04-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void chline(char ch, unsigned i, unsigned j)
{
    for (unsigned col = 0; col < i; col++)
    {
        putchar(' ');
    }
    for (unsigned col = i; col <= j; col++)
    {
        putchar(ch);
    }
    putchar('\n');
}

int main(void)
{
    char ch;
    unsigned i;
    unsigned j;

    printf("function chline(ch, i, j) that prints the requested character in columns i though j\n");

    while (true)
    {
        printf("input ch, i and j; input q to exit: \n");
        if (3 == scanf("%c %u %u", &ch, &i, &j))
        {
            printf("chline(\'%c\', %u, %u)\n", ch, i, j);
            chline(ch, i, j);
        }
    }

    return EXIT_SUCCESS;
}
