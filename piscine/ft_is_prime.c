#include <unistd.h>
#include <stdio.h>

int ft_is_prime(int nb);

int main()
{
    int x = 8;
    int result = ft_is_prime(x);
    printf("%d",result);
    return 0;
}

int ft_is_prime(int nb)
{
    if (nb <= 1)
    {
        return 0;
    }
    else
    {
        for(int i = 2; i < nb; i++)
        {
            if (nb % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
