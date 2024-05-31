#include <unistd.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
    char x[50] = "Hello, World";
    char y[] = "Hello, World";
    unsigned int z = 5;
    ft_strncat(x, y, z);
    return 0;
}

char *ft_strncat(char *dest, char *src, unsigned int nb)
{   int i = 0;
    int j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0' && j < nb)
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
