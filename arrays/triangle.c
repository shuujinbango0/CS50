#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool valid_triangle (float a, float b, float c);

int main(void)
{
    float a = get_int("Length of the first side: ");
    float b = get_int("Length of the second side: ");
    float c = get_int("Length of the third side: ");
    bool d = valid_triangle (a, b, c);
}
bool valid_triangle(float a, float b, float c)
{
    if  ((a < 0) || (b < 0) || (c < 0))
    {
        printf("false\n");
        return false;
    }
    if  ((a >= b +c) || (b >= a + c) || (c >= b + c))
    {
        printf("false\n");
        return false;
    }
    printf("true\n");
    return true;
}
