#include <unistd.h>
#include <stdio.h>

int ft_iterative_factorial(int nb);

int main (void)
{
    int x = 6;
    int factorial = ft_iterative_factorial(x);
    printf("%d",factorial);
    return 0;
}

int ft_iterative_factorial(int nb)
{
    if (nb < 0)
    {
        return 0;
    }
    int fact = nb;
    while (--fact)
    {
        nb *= fact;
    }

    return nb;
}
