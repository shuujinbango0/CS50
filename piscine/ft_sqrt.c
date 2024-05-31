#include <unistd.h>
#include <stdio.h>

int ft_sqrt(int nb);

int main(void)
{
    int x = 25;
    ft_sqrt(x);
    return 0;
}

int ft_sqrt(int nb)
{
    //Babylonian method: (g + n/g) / 2
    int guess = 1;
    while (guess++ < nb)
    {
        if(guess == (guess + nb/guess)/2)
        {
            printf("%d", guess);
            if (nb == (int)guess * (int)guess)
            {
                printf("%d", guess);
                return guess;
            }
            else
            {
                return 0;
            }
        }
    }
}

