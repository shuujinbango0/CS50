#include <unistd.h>

char *ft_strupcase(char *str);

int main (void)
{
    char hello[50] = "Hello, World!";
    ft_strupcase(hello);

    return 0;
}

char *ft_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] > 64 && str[i] < 91)
        {
            int temp = str[i] + 32;
            str[i] = temp;
            write(1,&temp,1);
        }

        else if ((str[i] > 31 && str[i] < 65) || (str[i] > 90 && str[i] < 127))
        {
            write(1,&str[i],1);
        }
        i++;
    }
    return str;
}

