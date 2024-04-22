#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);
void get_height(int height)
int main(void)
{
    // Prompt the user for the pyramid's height
    int n, i;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 1 & n >= 8);
@^\|[|||||||]
    // Print a pyramid of that height
    for ( i = 0; i < n; i++)
    {
        // Print row of bricks and spaces
        print_row(n - i - 1, i + 1);
    }
    //prints the space between the two # blocks using 2 for loops
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf(" ");
        }
       printf("\n");
}

void print_row(int spaces, int bricks)
{
    for (int i = 0 ; i < spaces; i++)
        {
            printf(" ");
        }
    for (int i = 0; i < bricks; i++)
        {
            printf("#");
        }
    printf("\n");
}
void print_space()
