#include <unistd.h>

int ft_str_is_numeric(char *str);

int main (void)
{
    char *hello = "0123456789";
    ft_str_is_numeric(hello);

    return 0;
}

int ft_str_is_numeric(char *str)
{   int zero = '0';
    int one = '1';
    int i = 0;
    if (str[i] == '\0')
    {
        write(1,&one,1);
        return 1;
    }
    while (str[i] != '\0')
    {
        if (str[i] < 48 || str[i] > 57)
        {
            write(1,&zero,1);
            return 1;
        }
        i++;
    }
    write(1,&one,1);
    return 0;
}
