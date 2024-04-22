#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int just_one(int argc);
int only_digits(string argv);
int wholetext(string plaintext, int k);
int main(int argc, string argv[])
{
    // number of command line argument
    int j = just_one(argc);
    // check if "k" contains only digits
    int d = only_digits(argv[1]);
    // convert k from a string to an integer
    int k = atoi(argv[1]);
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
int only_digits(string argv)
{
    for (int i = 0, len = strlen(argv); i < len; i++)
    {
        if (isdigit(argv[i]) == 0)
        {
            printf("Usage: ./caesar key");
            exit(1);
        }
    }
    return 0;
}
// apply it to the whole plain text
int wholetext(string plaintext, int k)
{
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    // Rotate the character if it's a letter
    {
        if (isalpha(plaintext[i]) != 0)
        {
            if (isupper(plaintext[i]))
            {
                int c = ((plaintext[i] - 'A' + k) % 26 + 'A');
                c = (char) c;
                printf("%c", c);
            }
            else
            {
                int c = ((plaintext[i] - 'a' + k) % 26 + 'a');
                c = (char) c;
                printf("%c", c);
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
