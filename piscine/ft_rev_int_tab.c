#include <unistd.h>

void ft_rev_int_tab(int *tab, int size);

int main (void){
    int array[5] = {1, 2, 3, 4, 5};
    ft_rev_int_tab(array, 5);
}

void ft_rev_int_tab(int *tab, int size){
    int temp[size];
    for(int i = 0; i < size ; i++){
        temp[i] = tab[i];
    }
    int k = 0;
    for (int j = size - 1; j >= 0; j--){
        tab[j] = temp[k];
        k++;
    }
    for(int i = 0; i < size ; i++){
        int temp2 = tab[i] + '0';
        write(1,&temp2,1);
    }
}
