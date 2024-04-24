#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int voters = 10;
    int rank = 20;
    int votes = 0;

    for (int i = 0; i < voters; i++)
    {
        for (int c = 0; c < rank ; c++)
        {
            votes ++;
            printf("%i\n", votes);
            break;
        }
    }
}
