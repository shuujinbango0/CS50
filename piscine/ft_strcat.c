#include <unistd.h>

char *ft_strcat(char *dest, char *src);

int main(void)
{
    char x[50] = "Hello, World";
    char y[] = "Hello, World";
    ft_strcat(x, y);
    return 0;
}

char *ft_strcat(char *dest, char *src)
{   int i = 0;
    int j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    i = 0;
    while (dest[i] != '\0')
    {
        write(1,&dest[i],1);
        i++;
    }
    return dest;
}
