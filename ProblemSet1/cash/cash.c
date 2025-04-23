#include <cs50.h>
#include <stdio.h>

int quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return (quarters);
}

int dimes(int cents)
{
    int dimes = 0;
    while(cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return (dimes);
}

int nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return (nickels);
}

int pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return (pennies);
}

int main(void)
{
    int cents;
    int quart;
    int dime;
    int nick;
    int penny;
    int sum;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    {
        quart = quarters(cents);
        cents = cents - (quart * 25);

        dime = dimes(cents);
        cents = cents - (dime * 10);

        nick = nickels(cents);
        cents = cents - (nick * 5);

        penny = pennies(cents);

        sum = quart + dime + nick + penny;
        printf("%i\n", sum);
    }

}
