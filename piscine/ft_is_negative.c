#include <unistd.h>

void ft_is_negative(int n);

int main () {
    int x = -5;
    ft_is_negative(x);
    return 0;
}

void ft_is_negative(int n){
    if (n < 0) {
        int i = 'N';
        write(1,&i,1);
    }
    else {
        int i = 'P';
        write(1,&i,1);
    }
    char* j = "\n";
    write(1,j,1);
}
