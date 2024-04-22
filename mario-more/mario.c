#include <cs50.h>
#include <stdio.h>
// I put the variables in the global scope
int n, i, s, b, j;
void print_row(int spaces, int bricks);
void get_height(void);
int main(void)
{

// Prompt the user for the pyramid's height using a function
    get_height();
// Print a pyramid of that height
    for (i = 0; i < n; i++)
    {
// Print row of bricks and spaces
        print_row(n - i - 1, i + 1);
    }
}

void print_row(int spaces, int bricks)
{
    for (s = 0; s < spaces; s++)
        {
            printf(" ");
        }
    for (b = 0; b < bricks; b++)
        {
            printf("#");
        }
    for (j = 0; j < 2; j++)
        {
            printf(" ");
        }
    for (b = 0; b < bricks; b++)
        {
            printf("#");
        }
    printf("\n");
}
void get_height()
{
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
}
