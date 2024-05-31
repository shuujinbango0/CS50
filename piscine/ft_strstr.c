#include <unistd.h>

char *ft_strstr(char *str, char *to_find);

int main (void)
{
    char *x = "Hello, World!";
    char *y= "W";
    ft_strstr(x, y);
    return 0;
}

char *ft_strstr(char *str, char *to_find)
{
    int i = 0;
    char *pointer;
    if (to_find[0] == '\0')
    {
        write(1,str,1);
        return str;
    }
    while (str[i] != '\0')
    {
        int j = 0;
        while (to_find[j] != '\0')
        {
            if (str[i] == to_find[j])
            {
                pointer = &str[i];
                while (*pointer != '\0')
                {
                    write(1,pointer,1);
                    pointer++;
                }
                return pointer;
            }
            j++;
        }
        i++;
    }
    return NULL;
}
