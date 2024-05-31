#include <unistd.h>

void ft_print_comb2(void);

int main (void){
    ft_print_comb2();
    return 0;
    }


void ft_print_comb2(void){
    int m = ',';
    int n = ' ';
    int total = '9'+'9'+'9'+'8';
    for(int i = '0'; i <= '9' ; i++){
        for(int j = '0'; j <= '8' ;j++){
            for(int k = '0'; k <= '9' ;k++){
               for(int l = '1'; l <= '9' ;l++){
                    if ((i+j) < (k + l)){
                        write(1,&i,1);
                        write(1,&j,1);
                        write(1,&n,1);
                        write(1,&k,1);
                        write(1,&l,1);
                        if (i + j + k + l != total){
                            write(1,&m,1);
                            write(1,&n,1);
                        }
                    }
                }
            }
        }
    }
}
