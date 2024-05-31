#include <unistd.h>

void ft_putstr_non_printable(char *str);

int main (void)
{
    char x[100] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(x);
    return 0;
}

void ft_putstr_non_printable(char *str)
{
    int i = 0;
    int zero = '0';
    int one = '1';
    int seven = '7';
    int back = '\\';
     while (str[i] != '\0')
     {
        if (str[i] < 32 || str[i] > 126)
        {
            one = '1';
            write(1,&back,1);
            if (str[i] > 10)
            {
                write(1,&zero,1);
                int temp0 = str[i] +'0';
                write(1,&temp0,1);
            }
            else if (str[i] > 9 && str[i] < 16)
            {
                write(1,&zero,1);
                int temp1 = str[i] + 87;
                write (1,&temp1,1);
            }
            else if (str[i] > 15 && str[i] < 26)
            {
                int temp2 = ((str[i] / 10) % 10) + '0';
                write (1,&temp2,1);
                temp2 = (str[i] % 10) + '0';
                write (1,&temp2,1);

            }
            else if (str[i] > 25 && str[i] < 32)
            {
                int temp3 = str[i] + 71;
                write(1, &one, 1);
                write(1, &temp3, 1);

            }
            else if (str[i] == 127)
            {
                int temp4 = 102;
                write(1,&seven,1);
                write(1,&temp4,1);
            }
        }
        else
        {
            write(1,&str[i],1);
        }
        i++;
     }
}
