#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int blocks_size = 512;

int main(void)
{
    //preciser love[10] ou juste love[] c est la meme chose
    //, parce que j ai enumere 10 elements dans l'array
    int love[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int j = 0; j < 10; j++)
    {
        if (love[j] > 5)
        //le code repete 4 fois la inner boucle i
        //i.e(le nombre d iterations de [j] > 5 de la premiere boucle)
        {
            for (int i = 0; i < 10; i++)
            {
            printf("%i\n", i);
            }
        }
    }
}
