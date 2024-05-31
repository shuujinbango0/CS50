#include <unistd.h>
#include <stdio.h>

int ft_find_next_prime(int nb);


int main()
{
    int x = 8;
    int result = ft_find_next_prime(x);
    printf("%d",result);
    return 0;
}

int ft_find_next_prime(int nb)
{
    if (nb < 0)
    {
        return 0;
    }
    else
    {
        int guess = nb + 1;
        while(guess++)
        {
            for(int j = 2 ; j < guess; j++)
            {
                if(guess % j == 0)
                {
                    break;
                }
                if(j == guess - 1)
                {
                    return guess;
                }
            }
        }
    }
    return 0;
}
