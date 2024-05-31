#include <unistd.h>

void ft_print_alphabet(void);

int main () {
    ft_print_alphabet ();
    return 0;
}

void ft_print_alphabet (void){
    int i = 'z';
    char* j = "\n";
    while (i >= 'a'){
        write(1,&i,1);
        i --;
    }
    write(1,j,1);
}
