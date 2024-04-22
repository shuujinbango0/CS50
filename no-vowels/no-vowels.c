// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <string.h>
#include <stdio.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    string word = argv[1];
    string translation = replace(word);
    printf("%s\n", translation);
}

string replace(string word)
{
    for (int i = 0, len = strlen(word); i < len; i++ )
    {
        switch (word[i]) {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                break;
        }
    }
    return word;
}
