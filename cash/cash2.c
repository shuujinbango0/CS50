#include <cs50.h>
#include <stdio.h>

int cents;
void ask_change(void);
int get_quarters(void);
int change_quarters(void);
int get_dimes(void);
int change_dimes(void);
int get_nickels(void);
int change_nickels(void);
int get_pennies(void);
int change_pennies(void);
int total_coins();
void total_answer();
int main(void)
{// Prompt the user for change owed, in cents
    ask_change();
    // Calculate how many quarters you should give customer
    // note to self #1 I learned that if i don't store those functions in a variable inside main, main just runs them and doesn't store the result anywhere
    int quarters = get_quarters();
    // Subtract the value of those quarters from cents
    int change_q = change_quarters();
    // Calculate how many dimes you should give customer
    int dimes = get_dimes();
    // Subtract the value of those dimes from remaining cents
    int change_d = change_dimes();
    // Calculate how many nickels you should give customer
    int nickels = get_nickels();
    // Subtract the value of those nickels from remaining cents
    int change_n = change_nickels();
    // Calculate how many pennies you should give customer
    int pennies = get_pennies();
    // Subtract the value of those pennies from remaining cents
    int change_p = change_pennies();
    // Sum the number of quarters, dimes, nickels, and pennies used
    int total_c = total_coins();
    // Print that sum
    //note to self#2 I learned that if you leave void in front of a function you cannot call it, it is used to reference it only
    total_answer();
}
void ask_change()
{
    do
    {
       cents = get_int("Change owed: ");
    }
    while (cents < 1);
}
int get_quarters()
{
    {
        int quarters = cents/25;
        return quarters;
     }
}
int change_quarters()
{
    {
       int change_q = cents - (get_quarters()*25);
       return change_q;
    }
}
int get_dimes()
{
    {
        int dimes = change_quarters()/10;
        return dimes;
     }
}
int change_dimes()
{
    {
       int change_d = change_quarters() - (get_dimes()*10);
       return change_d;
    }
}
int get_nickels()
{
    {
        int nickels = change_dimes()/5;
        return nickels;
     }
}
int change_nickels()
{
    {
       int change_n = change_dimes() - (get_nickels()*5);
       return change_n;
    }
}
int get_pennies()
{
    {
        int pennies = change_nickels()/1;
        return pennies;
     }
}
int change_pennies()
{
    {
       int change_p = change_nickels() - (get_pennies()*1);
       return change_p;
    }
}
int total_coins()
{
    int total = get_quarters() + get_dimes() + get_nickels() + get_pennies();
    return total;
}
void total_answer()
{
    printf("%i\n", total_coins());
}
