#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str);

int main (void)
{
    char *x = "   ---+--+1234ab567";
    int result = ft_atoi(x);
    return result;
}

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 0;
    int counter = 10;
    int final = 0;

    if(str[0] == ' ')
    {
        while(str[i] == ' ')
        {
            i++;
        }
    }
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            sign ++;
            i++;
        }
        else
        {
            i++;
        }
    }
    int sign2 = (sign) % 2;
    if (sign2 != 0)
    {
        int minus = '-';
        write(1,&minus,1);
        sign = -1;
    }
    else
    {
        sign = 1;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
            int temp = str[i];
            write(1,&temp,1);
            final = final * 10 + (str[i] - '0');
            i++;
    }
    final *= sign;

    return final;
}

