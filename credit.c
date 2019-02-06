#include <stdio.h>
#include <math.h>
#include <cs50.h>

long digit_adder(long n);
long first_digits(long m, int x);

int main(void)
{
    long number = get_long("Number: ");
    if (digit_adder(number) != 0 || (int) (floor(log10(number)) +1) != 16)
    {
        printf("INVALID\n");
    } else if (first_digits(number, 2) == 51 || first_digits(number, 2) == 52 || first_digits(number, 2) == 53 || first_digits(number, 2) == 54 || first_digits(number, 2) == 55)
    {
        printf("MASTERCARD\n");
    } else if (first_digits(number, 1) == 4)
    {
        printf("VISA\n");
    } else
    {
        printf("AMEX\n");
    }
    
}

long digit_adder(long n)
{
    long sum_first = 0;
    for (int i = 0; i < 8; i++)
    {
        long start = n % (long) pow(10, 2*i+2);
        sum_first += ((n % (long) pow(10, 2*i+3) - start)/pow(10, 2*i+2));
    }
    sum_first += (n % 10);
    
    long sum_second = 0;
    for (int i = 0; i < 8; i++)
    {
        long start = n % (long) pow(10, 2*i+1);
        int addend = (((n % (long) pow(10, 2*i+2) - start)/pow(10, 2*i+1)) * 2);
        sum_second += ((addend % 10) + ((addend % 100) - (addend % 10))/10);
    } 
    return ((sum_first + sum_second) % 10);
}

long first_digits(long m, int x)
{
    return ((m - (m % (long) pow(10, (16-x))))/pow(10, (16-x)));
}
