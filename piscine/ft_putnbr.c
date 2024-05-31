#include <unistd.h>

void ft_putnbr(int nb);

int main(void){
    int x = -700;
    ft_putnbr(x);
    return 0;
}

void ft_putnbr(int nb){
    int array[10];
    int index = 0;
    if (nb >= 0){
            int number = '0' + (nb % 10);
            array[index] = number;
            while (nb > 10){
                nb /= 10;
                index ++;
                number = '0' + (nb % 10);
                array[index] = number;
            }
            for (int i = index; i >= 0; i--){
                write(1,&array[i],1);
            }
    }
    else {
        int minus = '-';
        write(1,&minus,1);
        int number = '0' + (-nb % 10);
        array[index] = number;
        while (nb < -10){
                nb /= 10;
                index ++;
                number = '0' + (-nb % 10);
                array[index] = number;
            }
            for (int i = index; i >= 0; i--){
                write(1,&array[i],1);
            }
    }
}

