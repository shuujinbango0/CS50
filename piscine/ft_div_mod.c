#include <unistd.h>


void ft_div_mod(int a, int b, int *div, int *mod);

int main (void){
    int x = 4;
    int y = 2;
    int div;
    int mod;
    ft_div_mod(x, y, &div, &mod);
}


void ft_div_mod(int a, int b, int *div, int *mod){
    *div = a / b;
    *mod = a % b;
    int temp1 = *div + '0';
    int temp2 = *mod + '0';
    write(1,&temp1,1);
    write(1,&temp2,1);
}
