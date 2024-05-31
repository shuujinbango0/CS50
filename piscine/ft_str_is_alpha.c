#include <unistd.h>

int ft_str_is_alpha(char *str);

int main (void)
{
    char *hello = "hi";
    ft_str_is_alpha(hello);

    return 0;
}

int ft_str_is_alpha(char *str)
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
        if (str[i] < 65 || str[i] > 122 || (str[i] > 90 && str[i] < 97))
        {
            write(1,&zero,1);
            return 1;
        }
        i++;
    }
    write(1,&one,1);
    return 0;
}
