#include <unistd.h>

char *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void){
    char x[50] = "Hello, World!";
    char *y = "Bonjour!";
    int z = 3;
    ft_strncpy(x, y, z);
    return 0;
}


char *ft_strncpy(char *dest, char *src, unsigned int n){
    int i = 0;
    while (i < n)
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
