#include <cs50.h>
#include <stdio.h>

void get_height(int height);
int main(void)
int middle(void)
{
    // Prompt the user for the pyramid's height
    int n, i, j;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 1 & n >= 8);

    // Print a pyramid of that height
    for ( i = 0; i < n; i++)
    {
    //prints the space between the two # blocks using 2 for loops
        for (j = 0; j < 2; j++)
        {
            printf(".");
        }
       printf("\n");
    }
}
