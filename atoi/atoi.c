#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int total = 0;
    int len = strlen(input);
    for (int i = len - 1 , j = 1; i >= 0 ; i--)
    {
        int num_value = (input[i] - '0' )* j;
        total += num_value;
        j *= 10;
    }
    return total;
}
