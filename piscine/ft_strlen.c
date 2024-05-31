#include <unistd.h>

int ft_strlen(char *str);

int main (void)
{
    char *x = "Hello, World!";
    ft_strlen(x);
    return 0;
}

int ft_strlen(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
    int temp = i;
    temp = (temp / 10) + '0';
    int temp2 = (i % 10) + '0';
    write(1,&temp,1);
    write(1,&temp2,1);

   return i;
}

