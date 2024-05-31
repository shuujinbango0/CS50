#include <unistd.h>

void ft_putstr(char *str);

int main (void){
    char *str = "Hello, World!";
    ft_putstr(str);
    return 0;
}

void ft_putstr(char *str){
    int i = 0;
    while (str[i] != '\0'){
        int temp = str[i];
        write(1,&temp,1);
        i++;
   }
}
