#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int just_one(int argc);
int only_digits(string argv);
int wholetext(string plaintext, int rotatevalue);
char rotate(char p, long k);
int main(int argc, string argv[])
{
    //number of command line argument
    int j = just_one(argc);
    //check if "k" contains only digits
    int d = only_digits(argv[1]);
    //convert k from a string to an integer
    int k = atoi(argv[1]);
    //prompt for plaintext
    string plaintext = get_string("plaintext:  ");
    int rotatevalue = rotate(char p, long k);
    //print cyphertext:
    printf("ciphertext: %c", wholetext(plaintext, rotatevalue));
    //rotate over every character of plain text
}
int just_one(int argc)
{
    if(argc != 2)
    {
        printf("Please enter one and only one command line argument");
    }
    return 1;
}
int only_digits(string argv)
{
    if(isdigit(argv[1]) == 0)
    {
        printf("Usage: ./caesar key");
    }
    return 1;
}
char rotate(char p, long k)
{
    if(isalpha(p) != 0)
    {
        if(isupper(p))
        {
            int c = 'p' - 'A' + (k % 26);
            c = (char)c
            return c;
        }
        else
        {
            int c = 'p' - 'a' + (k % 26);
            c = (char)c
            return c;
        }
    }
    else
    {
        int c = p;
        c = (char)c
        return c;
    }
}
    //apply it to the whole plain text
int wholetext(string plaintext, int rotatevalue)
{
    for(int i = 0, len = strlen(plaintext), char p = plaintext[i]; i < len; i++)
    // Rotate the character if it's a letter
    {
        printf("%c",
    }
}
