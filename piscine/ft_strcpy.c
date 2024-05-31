#include <unistd.h>

char *ft_strcpy(char *dest, char *src);

int main(void){
    char x[50] = "Hello, World!";
    char *y = "Bonjour!";
    ft_strcpy(x, y);
    return 0;
}


char *ft_strcpy(char *dest, char *src){
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
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
