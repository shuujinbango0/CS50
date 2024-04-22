#include <cs50.h>
#include <stdio.h>

int first_sum(long card_number);
int second_sum(long card_number);
int card_length(long card_number);
int Amex_op(int length, int f, long card_number);
int Mastercard_op(int length, int f, long card_number);
int VISA_op(int length, int f, long card_number);
int main(void)
{
    // Prompt the user for credit card number (card_number)
    long card_number;
    do
    {
        card_number = get_long("Credit card number: ");
    }
    while (card_number < 0);

    int c = first_sum(card_number);
    int e = second_sum(card_number);
    int f = (c + e) % 10;
    int length = card_length(card_number);
    int Amex = Amex_op(length, f, card_number);
    int Mastercard = Mastercard_op(length, f, card_number);
    int Visa = VISA_op(length, f, card_number);

    if (f != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (length != 15)
    {
        if (length != 16)
        {
            if (length != 13)
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }

    if (Amex == 0)
    {
        if (Mastercard == 0)
        {
            if (Visa == 0)
            {
                printf("INVALID\n");
            }
            return 0;
        }
    }
}
int first_sum(long card_number)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while (card_number >= 1)
    {
        card_number /= 10;
        a = card_number % 10;
        b = a * 2;
        while (b >= 1)
        {
            c += b % 10;
            b /= 10;
        }
        card_number /= 10;
    }
    return c;
}
int second_sum(long card_number)
{
    int d = 0;
    int e = 0;
    while (card_number >= 1)
    {
        d = card_number % 10;
        e += d;
        card_number /= 10;
        card_number /= 10;
    }
    return e;
}
int card_length(long card_number)
{
    int length = 0;
    while (card_number >= 1)
    {
        card_number /= 10;
        length++;
    }
    return length;
}
int Amex_op(int length, int f, long card_number)
{
    int Amex = 0;

    if (f == 0)
    {
        if (length == 15)
        {
            if ((card_number >= 340000000000000 && card_number <= 349999999999999) ||
                (card_number >= 370000000000000 && card_number <= 379999999999999))
            {
                printf("AMEX\n");
                Amex = 1;
            }
        }
    }
    return Amex;
}
int Mastercard_op(int length, int f, long card_number)
{
    int Mastercard = 0;
    if (f == 0)
    {
        if (length == 16)
        {
            if ((card_number >= 5100000000000000 && card_number <= 5199999999999999) ||
                (card_number >= 5200000000000000 && card_number <= 5299999999999999) ||
                (card_number >= 5300000000000000 && card_number <= 5399999999999999) ||
                (card_number >= 5400000000000000 && card_number <= 5499999999999999) ||
                (card_number >= 5500000000000000 && card_number <= 5599999999999999))
            {
                printf("MASTERCARD\n");
                Mastercard = 1;
            }
        }
    }
    return Mastercard;
}
int VISA_op(int length, int f, long card_number)
{
    int Visa = 0;

    if (f == 0)
    {
        if (length == 13)
        {
            if (card_number >= 4000000000000 && card_number <= 4999999999999)
            {
                printf("VISA\n");
                Visa = 1;
            }
        }
        else if (length == 16)
        {
            if (card_number >= 4000000000000000 && card_number <= 4999999999999999)
            {
                printf("VISA\n");
                Visa = 1;
            }
        }
    }
    return Visa;
}
