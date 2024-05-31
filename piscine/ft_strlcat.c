#include <unistd.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main (void)
{
    char x[50] = "Everybody";
    char y[] =" Want Somebody";
    int z = 14;
    ft_strlcat(x, y , z);
    return 0;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{   int i = 0;
    int j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (j < size)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    int k = 0;
    while (dest[k] != '\0')
    {
        write(1,&dest[k],1);
        k++;
    }
    int total = i + j;
    return total;
}
