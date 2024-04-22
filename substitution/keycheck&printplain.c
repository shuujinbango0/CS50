#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int just_one(int argc);
int key_chek(string argv);
int main(int argc, string argv[])
{
    // number of command line argument
    int j = just_one(argc);
    // check if "k" is valid: 26 characters, only alphabetical and no repeat letters
    int d = key_chek(argv[1]);
    // convert k from a string to an integer
    // prompt for plaintext
    string plaintext = get_string("plaintext:  ");
    // print cyphertext:
    printf("ciphertext: ");
    wholetext(plaintext, k);
    // rotate over every character of plain text
}
int just_one(int argc)
{
    if (argc != 2)
    {
        printf("Please enter one and only one command line argument");
        exit(1);
    }
    return 1;
}
int key_chek(string argv)
{
    int len = strlen(argv);
    if len != 26
    {
        printf("Please print 26 alphabetical characters");
        exit(1);
    }
    else
    {
        for (int i = 0 ; i < len - 1; i++)
        {
            if (isalpha(argv[i]) == 0)
            {
                printf("Please input only alphabetical characters");
                exit(1);
            }
            for (int j = i + 1 ; j < len; j++)
            {
                if (argv[i]) == argv[j])
                {
                    printf("Please do not input repeat letters in the sequence");
                    exit(1);
                }
            }

        }
    }
    return 0;
}
