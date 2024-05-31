#include <unistd.h>

void *ft_print_memory(void *addr, unsigned int size);

int main (void)
{
    char x[92] ="Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
    ft_print_memory(x, 92);

    return 0;
}

void *ft_print_memory(void *addr, unsigned int size)
{
    char *charpoint = addr;
    char buffer[17];
    char hex_chars[] = "0123456789ABCDEF";
    char hex[2];
    int i = 0;
    int dot = '.';
    int colon = ':';
    int space = ' ';
    int nl = '\n';
    if (size == 0)
    {
        return addr;
    }
    else
    {
        while (i < size)
        {
            if (i % 16 == 0)
            {
                if (i >= 16)
                {
                    write(1,&space,1);
                    for (int k = i - 16; k < i; k++)
                    {
                        char c = (char)charpoint[k];
                        if (c < 32 || c > 126)
                        {
                            write(1,&dot,1);
                        }
                        else
                        {
                            write(1,&c,1);
                        }
                    }
                    write(1,&nl,1);
                }
                int j;
                unsigned long address = (unsigned long)&addr[i];
                for (j = 15; j >= 0; j--)
                {
                    buffer[j] = hex_chars[address % 16];
                    address /= 16;
                }
                buffer[16] = '\0';
                write(1, buffer, 16);
                write(1,&colon,1);
                write(1,&space,1);
            }

            hex[0] = hex_chars[(charpoint[i] / 16)];
            hex[1] = hex_chars[(charpoint[i] % 16)];
            write(1, &hex[0], 1);
            if (hex[1] >= 'A' )
            {
                int temp = hex[1] + ' ';
                write(1, &temp, 1);
            }
            else
            {
                write(1, &hex[1], 1);
            }
            int mod = i % 2;
            if (mod == 1)
            {
                write(1,&space,1);
            }
            i++;
        }

        if (i % 16 != 0)
        {
            int check = 16 - (i % 16);
            for (int j = 0; j < check; j++)
            {
                write(1, &space, 1);
                write(1, &space, 1);
            }
            write(1, &space, 1);
            write(1, &space, 1);
            write(1, &space, 1);
        }
        for (int l = i - (i % 16); l < size; l++)
        {
                char d = (char)charpoint[l];
                if (d < 32 || d > 126)
                {
                    write(1,&dot,1);
                }
                else
                {
                    write(1,&d,1);
                }
        }
    }
    return addr;
}
