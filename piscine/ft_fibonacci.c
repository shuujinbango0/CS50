#include <unistd.h>
#include <stdio.h>

int ft_fibonacci(int index);


int main (void)
{
    int n = 6;
    int result = ft_fibonacci(n);
    printf("%d", result);
    return 0;
}

int ft_fibonacci(int index)
{
    if (index < 0)
    {
        return -1;
    }
    else if (index == 0)
    {
        return 0;
    }
    else if (index == 1)
    {
        return 1;
    }
    else
    {
        int fib = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
        printf("%d", fib);
        return fib;
    }
    //in fibonacci sequence: 0,1,1,2,3,5,8
    // 6 is 8
}
