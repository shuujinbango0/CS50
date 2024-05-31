#include <unistd.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main (void)
{
    char x[100] = {0};
    char *y = "Hello, World!";
    ft_strlcpy(x, y, 14);
    return 0;
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i = 0;
    while (i < size)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    int length = size - 1;
    i = 0;
    while (i < size)
    {
        write(1,&dest[i],1);
        i++;
    }
    return length;
}
