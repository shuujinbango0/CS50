#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert (string hexatext);
int main(int argc, string argv[])
{
//prompt for hexa text:
string hexatext = get_string("please input hexadecimal text: ");
convert(hexatext);
}

void convert (string hexatext)
{
//iterate over every character and add them to an array by pairs of two:
    for (int i = 0; i < strlen(hexatext); i ++)
    {
        if (hexatext[i] != '%')
        {
            char temp[3] = {hexatext[i], hexatext[i + 1], '\0'};
            unsigned int number;
            sscanf(temp, "%x", &number);
            printf("%c", number);
        }
    }
    printf("\n");
}

