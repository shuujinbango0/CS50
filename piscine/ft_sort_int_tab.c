#include <unistd.h>

void ft_sort_int_tab(int *tab, int size);

int main (void){
    int array[5] = {5, 2, 3, 4, 1};
    ft_sort_int_tab(array, 5);
}

void ft_sort_int_tab(int *tab, int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (tab[j] > tab[j + 1]){
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    for (int k = 0; k < size; k++){
        int temp2 = tab[k] + '0';
        write(1, &temp2, 1);
    }
}

