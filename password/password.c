// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int up = 0;
    int low = 0;
    int num = 0;
    int sym = 0;
    int len = strlen(password);

    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            up ++;
        }

        else if (islower(password[i]))
        {
            low ++;
        }

        else if (isdigit(password[i]))
        {
            num ++;
        }

        else
        {
            sym ++;
        }
    }
    if (up > 0 && low > 0 && num > 0 && sym > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
