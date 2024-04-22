#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int just_one(int x);
int key_chek(string y);
int substitute(string plaintext, string key);
int main(int argc, string argv[])
{
    // number of command line argument
    int j = just_one(argc);
    // convert argv[1] to a string key
    string key = argv[1];
    // check if "k" is valid: 26 characters, only alphabetical and no repeat letters
    int k = key_chek(key);
    // prompt for plaintext
    string plaintext = get_string("plaintext:  ");
    // print cyphertext:
    printf("ciphertext: ");
    int cyphertext = substitute(plaintext, key);
    // rotate over every character of plain text
    return (0);
}
int just_one(int x)
{
    if (x != 2)
    {
        printf("Please enter one and only one command line argument");
        exit(1);
    }
    return 1;
}
int key_chek(string y)
{
    int len = strlen(y);
    if (len != 26)
    {
        printf("Please print 26 alphabetical characters");
        exit(1);
    }
    else
    {
        for (int i = 0; i < len - 1; i++)
        {
            if (isalpha(y[i]) == 0)
            {
                printf("Please input only alphabetical characters");
                exit(1);
            }
            for (int j = i + 1; j < len; j++)
            {
                if (y[i] == y[j])
                {
                    printf("Please do not input repeat letters in the sequence");
                    exit(1);
                }
            }
        }
    }
    return 0;
}
// apply it to the whole plain text
int substitute(string plaintext, string key)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]) != 0)
        {
            if (isupper(plaintext[i]))
            {
                int j = plaintext[i] - 'A';
                printf("%c", toupper(key[j]));
            }
            else
            {
                int k = plaintext[i] - 'a';
                printf("%c", tolower(key[k]));
            }
        }
        else
        {
            int f = plaintext[i];
            f = (char) f;
            printf("%c", f);
        }
    }
    printf("\n");
    return 0;
}
