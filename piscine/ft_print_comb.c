#include <unistd.h>

void ft_print_comb(void);

int main(void){
    ft_print_comb();
    return 0;
}

void ft_print_comb(void){
    int l = ',';
    int m = ' ';
    int index = '7' +'8' + '9';
    for(int i = '0'; i <= '7'; i++){
        for(int j = '1'; j <= '8'; j++){
            for (int k = '2'; k <= '9'; k++){
                if ((i + j) < ){
                    write(1,&i,1);
                    write(1,&j,1);
                    write(1,&k,1);
                    if (i + j + k != index){
                        write(1,&l,1);
                        write(1,&m,1);
                    }
                }
            }
        }
    }
}

