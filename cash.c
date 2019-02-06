#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int coin_count = 0;
    float dollars;
    do
    {
        dollars = get_float("Change: ");
    }
    while (dollars < 0);
    int coins = round(dollars * 100);
    while (coins - 25 >= 0)
    {
        coin_count++;
        coins -= 25;
    }
    while (coins - 10 >= 0)
    {
        coin_count++;
        coins -= 10;
    }
    while (coins - 5 >= 0)
    {
        coin_count++;
        coins -= 5;
    }
    while (coins - 1 >= 0)
    {
        coin_count++;
        coins -= 1;
    }
    printf("I have %i coin(s)\n", coin_count);
}
