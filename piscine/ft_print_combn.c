#include <unistd.h>
#include <stdio.h>

void ft_print_combn(int n);

int main (void)
{
    int x = 3;
    ft_print_combn(x);
    return 0;
}

//since we start counting arrays from 0, the total number of arrays is n - 1
void ft_print_combn(int n){
    int array[n];
    int max10 = 10;
    int temp = 0;
    int space = ' ';
    int coma = ',';
    if (n < 1 || n > 10)
    {
        return;
    }
    else
    {
        for (int i = 0; i < n ;i++) // wrote the first entry.
        {
            array[i] = i;
            temp = i + '0';
            write(1,&temp,1);
        }
        write(1,&coma,1);
        write(1,&space,1);
        // FIRST PART OVER
        //SECOND PART WE WANT THE VALUES OF EACH AND COMPARE THEM TO THE MAX DIGIT
        //here i iterate from right to left, and
        while (1){
            int pos = n -1;
            int value = array[pos];
            while (pos >= 0 && array[pos] == 10 - n + pos) {
                pos--;
                if (pos < 0){
                break;
                }
                array[pos]++;
                // Reset all subsequent digits
                for (int i = pos + 1; i < n; i++) {
                    array[i] = array[i - 1] + 1;
                }
                for (int i = 0; i < n; i++) {
                temp = array[i] + '0';
                write(1, &temp, 1);
                }
                write(1, &coma, 1);
                write(1, &space, 1);
            }
        }
    }
}


















