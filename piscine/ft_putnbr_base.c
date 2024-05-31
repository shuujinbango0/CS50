#include <unistd.h>

void ft_putnbr_base(int nbr, char *base);

int main (void)
{
    int x = 42;
    char *decimal = "0123456789";
    char *binary = "01";
    char *hexadecimal = "0123456789ABCDEF";
    char *octal = "poneyvif";
    ft_putnbr_base(x, hexadecimal);
    return 0;
}

void ft_putnbr_base(int nbr, char *base)
{
    int pos = 0;
    if(base[0] == '\0' || base[1] == '\0')
    {
        return;
    }

    while(base[pos] != '\0')
    {
        if (base[pos] == '+' || base[pos] == '-' || base[pos] == ' ' || base[pos] < 33 || base[pos] > 126)
        {
            return;
        }
        pos++;
    }
    int basemax = pos;
    pos = 0;
    int j = 1;
    while(base[pos] != '\0' && base[j] != basemax)
    {
        if(base[pos] == base[j])
        {
            return;
        }
        j++;
        pos++;
    }
// NOW THAT WE HAVE EXCLUDED THE CASES WERE THERE S AN INVALID ARGUMENT
// LET S ITERATE THROUGH BASES AND GET TO THE HEART OF THE FUNCTION
    int sign = 1;
// LET S CHECK IF NBR IS NEGATIVE OR POSITIVE AND
// MAKE IT POSITIVE TEMPORARILY TO DEAL WITH IT EASIER??
    if(nbr == 0)
    {
        write(1,&base[0],1);
        return;
    }

    else if(nbr < 0)
    {
        sign = -1;
        int minus = '-';
        write(1,&minus,1);
        nbr = nbr * sign;
    }
    pos = 0;
    int number[1000] = {'\0'};
    int test = nbr;
    while (test > 0)
    {
        number[pos] = test % basemax;
        test /= basemax;
        pos ++;
    }
    while (pos--)
    {
        char temp = base[number[pos]];
        write(1,&temp,1);
    }
}
