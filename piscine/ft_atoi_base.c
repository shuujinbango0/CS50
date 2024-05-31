#include <unistd.h>
#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main (void)
{
    char * x = "124A";
    char *decimal = "0123456789";
    char *binary = "01";
    char *hexadecimal = "0123456789ABCDEF";
    char *octal = "poneyvif";
    int final = ft_atoi_base(x, hexadecimal);
    printf("%d", final);
    return 0;
}

int ft_atoi_base(char *str, char *base)
{

// we check for invalid base inputs and get basemax.
    int pos = 0;
    if(base[0] == '\0' || base[1] == '\0')
    {
        return 0;
    }
    while(base[pos] != '\0')
    {
        if (base[pos] == '+' || base[pos] == '-' || base[pos] == ' ' || base[pos] < 33 || base[pos] > 126)
        {
            return 0;
        }
        for(int j = pos + 1; base[j] != '\0' ; j++)
        {
            if (base[pos] == base[j])
            {
                return 0;
            }
        }
        pos++;
    }
    int basemax = pos;
// then we check for invalid str inputs and transform the string into an int
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
// str[i] = 'A' in hexa for instance it corresponds to base[10]
// let s say for 124A in hexa which is 4682 in decimal
    i = 0;
    int result = 0;
    while(str[i] != '\0')
    {
        int j = 0;
        while (j < basemax)
        {
            if (str[i] == base[j])
            {
                result = result * basemax + j;
                break;
            }
            j++;
         }
        if (j == basemax)
        {
            return 0; // Invalid character for the given base
        }
        i++;
    }

   return result *= sign;
}
