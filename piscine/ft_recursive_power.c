#include <unistd.h>
#include <stdio.h>

int ft_recursive_power(int nb, int power);

int main (void)
{
    int x = 5;
    int y = 3;
    int result = ft_recursive_power(x, y);
    printf("%d", result);
    return 0;
}

int ft_recursive_power(int nb, int power)
{
    if (power == 0 && nb == 0)
    {
        return 1;
    }
    else if (power == 0)
    {
        return 1;
    }
    else if (power == 1)
    {
        return nb;
    }
    else
    {
        nb *= ft_recursive_power(nb, power - 1);
    }
}
