#include <unistd.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
    char *x = "Hello, World";
    char *y = "Hello, World";
    int z = 5;
    ft_strncmp(x, y, z);
    return 0;
}

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int zero = '0';
    int one = '1';
    int minus = '-';
    int i = 0;
    while (i < n)
    {
        if (s1[i] > s2[i])
        {
            write(1,&one,1);
            return 1;
        }
        else if (s2[i] > s1[i])
        {
            write(1,&minus,1);
            write(1,&one,1);
            return -1;
        }
        i++;
    }
    write(1,&zero,1);
    return 0;
}
