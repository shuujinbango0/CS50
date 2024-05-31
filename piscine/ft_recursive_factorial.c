#include <unistd.h>
#include <stdio.h>

int ft_recursive_factorial(int nb);

int main (void)
{
    int x = 6;
    int factorial = ft_recursive_factorial(x);
    printf("%d",factorial);
    return 0;
}

int ft_recursive_factorial(int nb)
{
    if (nb < 0)
    {
        return 0;
    }
    else if (nb == 0 || nb == 1)
    {
        return 1;
    }
    else
    {
        nb *= ft_recursive_factorial(nb - 1);
    }
}
