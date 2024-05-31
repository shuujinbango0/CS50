#include <unistd.h>

char *ft_strcapitalize(char *str);

int main (void)
{
    char hello[100] = "salUt, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    ft_strcapitalize(hello);

    return 0;
}

char *ft_strcapitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (i == 0 && str[i] > 96 && str[i] < 123)
        {
            int temp = str[i] - 32;
            str[i] = temp;
        }
        else if ((str[i] > 31 && str[i] < 65) && (str[i + 1] > 96 && str[i + 1] < 123))
        {
            int temp2 = str[i + 1] - 32;
            str[i + 1] = temp2;
        }
        else if (((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)) && (str[i + 1] > 64 && str[i + 1] < 91))
        {
            int temp3 = str[i + 1] + 32;
            str[i + 1] = temp3;
        }
        write(1,&str[i],1);
        i++;
    }
    return str;
}

