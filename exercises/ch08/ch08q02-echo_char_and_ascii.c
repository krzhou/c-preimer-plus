/**
 * @file ch08q02-echo_char_and_ascii.c
 * @author Eric Zhou (kr_zhou@outlook.com)
 * @brief Chapter 08 - Programming Exercise 02
 * Read characters until EOF and print each character with its ASCII decimal value.
 * @date 2023-01-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define PAIR_CNT_PER_LINE 10
#define ASCII_TABLE_SIZE 128

const char *ASCII_2_PRINTABLE[ASCII_TABLE_SIZE] = {
    "\\0", /* 000 null */
    "SOH", /* 001 start of heading */
    "STX", /* 002 start of text */
    "ETX", /* 003 end of text */
    "EOT", /* 004 end of transmission */
    "ENQ", /* 005 enquiry */
    "ACK", /* 006 acknowledge */
    "\\a", /* 007 bell */
    "\\b",  /* 008 backspace */
    "\\t",  /* 009 horizontal tab */
    "\\n",  /* 010 line feed */
    "\\v",  /* 011 vertical tab */
    "\\f",  /* 012 form feed */
    "\\r",  /* 013 carriage return */
    "SO",  /* 014 shift out */
    "SI",  /* 015 shift in */
    "DLE", /* 016 data link escape */
    "DC1", /* 017 device control 1 */
    "DC2", /* 018 device control 2 */
    "DC3", /* 019 device control 3 */
    "DC4", /* 020 device control 4 */
    "NAK", /* 021 negative acknowledge */
    "SYN", /* 022 synchronize */
    "ETB", /* 023 end of transmission Block */
    "CAN", /* 024 cancel */
    "EM",  /* 025 end of medium */
    "SUB", /* 026 substitute */
    "ESC", /* 027 escape */
    "FS",  /* 028 file separator */
    "GS",  /* 029 group separator */
    "RS",  /* 030 record separator */
    "US",  /* 031 unit separator */
    " ",    /*032  space */
    "!",   /* 033 exclamation mark */
    "\"",  /* 034 double quote */
    "#",   /* 035 number */
    "$",   /* 036 dollar sign */
    "%",   /* 037 percent */
    "&",   /* 038 ampersand */
    "\'",  /* 039 single quote */
    "(",   /* 040 left parenthesis */
    ")",   /* 041 right parenthesis */
    "*",   /* 042 asterisk */
    "+",   /* 043 plus */
    ",",   /* 044 comma */
    "-",   /* 045 minus */
    ".",   /* 046 period */
    "/",   /* 047 slash */
    "0",   /* 048 zero */
    "1",   /* 049 one */
    "2",   /* 050 two */
    "3",   /* 051 three */
    "4",   /* 052 four */
    "5",   /* 053 five */
    "6",   /* 054 six */
    "7",   /* 055 seven */
    "8",   /* 056 eight */
    "9",   /* 057 nine */
    ":",   /* 058 colon */
    ";",   /* 059 semicolon */
    "<",   /* 060 less than */
    "=",   /* 061 equality sign */
    ">",   /* 062 greater than */
    "?",   /* 063 question mark */
    "@",   /* 064 at sign */
    "A",   /* 065 capital a */
    "B",   /* 066 capital b */
    "C",   /* 067 capital c */
    "D",   /* 068 capital d */
    "E",   /* 069 capital e */
    "F",   /* 070 capital f */
    "G",   /* 071 capital g */
    "H",   /* 072 capital h */
    "I",   /* 073 capital i */
    "J",   /* 074 capital j */
    "K",   /* 075 capital k */
    "L",   /* 076 capital l */
    "M",   /* 077 capital m */
    "N",   /* 078 capital n */
    "O",   /* 079 capital o */
    "P",   /* 080 capital p */
    "Q",   /* 081 capital q */
    "R",   /* 082 capital r */
    "S",   /* 083 capital s */
    "T",   /* 084 capital t */
    "U",   /* 085 capital u */
    "V",   /* 086 capital v */
    "W",   /* 087 capital w */
    "X",   /* 088 capital x */
    "Y",   /* 089 capital y */
    "Z",   /* 090 capital z */
    "[",   /* 091 left square bracket */
    "\\",  /* 092 backslash */
    "]",   /* 093 right square bracket */
    "^",   /* 094 caret / circumflex */
    "_",   /* 095 underscore */
    "`",   /* 096 grave / accent */
    "a",   /* 097 small a */
    "b",   /* 098 small b */
    "c",   /* 099 small c */
    "d",   /* 100 small d */
    "e",   /* 101 small e */
    "f",   /* 102 small f */
    "g",   /* 103 small g */
    "h",   /* 104 small h */
    "i",   /* 105 small i */
    "j",   /* 106 small j */
    "k",   /* 107 small k */
    "l",   /* 108 small l */
    "m",   /* 109 small m */
    "n",   /* 110 small n */
    "o",   /* 111 small o */
    "p",   /* 112 small p */
    "q",   /* 113 small q */
    "r",   /* 114 small r */
    "s",   /* 115 small s */
    "t",   /* 116 small t */
    "u",   /* 117 small u */
    "v",   /* 118 small v */
    "w",   /* 119 small w */
    "x",   /* 120 small x */
    "y",   /* 121 small y */
    "z",   /* 122 small z */
    "{",   /* 123 left curly bracket */
    "|",   /* 124 vertical bar */
    "}",   /* 125 right curly bracket */
    "~",   /* 126 tilde */
    "DEL", /* 127 delete */
};

int main(void)
{
    int input_char;
    int count = 0;

    while (EOF != (input_char = getchar()))
    {
        /* Print each input character and its ASCII decimal value. */
        if (ASCII_TABLE_SIZE > input_char)
        {
            printf("%s\t%3d\t", ASCII_2_PRINTABLE[input_char], input_char);
        }
        else
        {
            printf("%c\t%3d\t", input_char, input_char);
        }

        /* Print 10 pairs per line. */
        count++;
        if (PAIR_CNT_PER_LINE == count)
        {
            printf("\n");
            count = 0;
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}
