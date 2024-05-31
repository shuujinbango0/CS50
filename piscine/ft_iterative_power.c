#include <unistd.h>
#include <stdio.h>

int ft_iterative_power(int nb, int power);

int main (void)
{
    int x = 6;
    int y = 3;
    int result = ft_iterative_power(x, y);
    printf("%d", result);
    return 0;
}

int ft_iterative_power(int nb, int power)
{
    if (power <= 0)
    {
        return 0;
    }
    else
    {
        int original = nb;
        while (power > 1)
        {
            power--;
            nb *= original;
        }
    }
    return nb;
}
