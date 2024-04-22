#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_l(string x);
int count_w(string x);
int count_s(string x);
float Compute_index(float x, float y, float z);
void print(int z);
int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    float letters = count_l(text);
    float words = count_w(text);
    float sentences = count_s(text);

    // Compute the Coleman-Liau index
    float index1 = Compute_index(letters, words, sentences);
    int index2 = round(index1);
    // Print the grade level
    print(index2);
}
int count_l(string x)
{
    int letters = 0;
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        if (isalpha(x[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}
int count_w(string x)
{
    int words = 1;
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        if (isblank(x[i]) != 0)
        {
            words++;
        }
    }
    return words;
}
int count_s(string x)
{
    int sentences = 0;
    for (int i = 0, len = strlen(x); i < len; i++)
    {
        if (x[i] == '.' || x[i] == '?' || x[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
float Compute_index(float x, float y, float z)
{
    float index = 0;
    float L = (x / y) * 100;
    float S = (z / y) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

void print(int z)
{
    if (z >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (z < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", z);
    }
}
