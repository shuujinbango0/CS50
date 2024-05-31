void ft_ultimate_div_mod(int *a, int *b);

void ft_ultimate_div_mod(int *a, int *b){
    int temp = *a / *b;
    int temp2 = *a % *b;
    *a = temp;
    *b = temp2;
}
