#include <unistd.h>

int ft_strcmp(char *s1, char *s2);

int main(void)
{
    char *x = "Hello, World";
    char *y = "Hello, World";
    ft_strcmp(x, y);
    return 0;
}

int ft_strcmp(char *s1, char *s2)
{
    int zero = '0';
    int one = '1';
    int minus = '-';
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
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
    if (s1[i] == '\0' && s2[i] != '\0')
    {
        write(1,&minus,1);
        write(1,&one,1);
        return -1;
    }
    else if (s2[i] == '\0' && s1[i] != '\0')
    {
        write(1,&one,1);
        return 1;
    }
    write(1,&zero,1);
    return 0;
}
