#include <stdio.h>
#include <cs50.h>

/*
American Express: 15-digits | start with 34 or 37
MasterCard: 16- digits | start with 51, 52, 53, 54 or 55
Visa: 13 & 16-digits | start with 4

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

Output: AMEX\n, MASTERCARD\n, VISA\n or INVALID\n
*/

bool luhn(long cc);

int main(void)
{
    // Ask for credit card number
    long cc = get_long("Number: ");

    // Find number of digits
    int digits = 0;
    long counter = cc;
    while (counter > 0)
    {
        counter /= 10;
        digits++;
    }

    // Needed for checking first digits
    int d13 = cc % 10000000000000 / 1000000000000;
    int d14 = cc % 100000000000000 / 10000000000000;
    int d15 = cc % 1000000000000000 / 100000000000000;
    int d16 = cc % 10000000000000000 / 1000000000000000;

    if (digits < 13)
    {
        // invalid <13 digits
        printf("INVALID\n");
    }
    else if (digits == 13)
    {
        // 13 digits
        if (d13 == 4)
        {
            if (luhn(cc))
            {
                printf("VISA\n");
            }
            else
            {
                // invalid not a credit card
                printf("INVALID\n");
            }
        }
        else
        {
            // invalid not VISA
            printf("INVALID\n");
        }
    }
    else if (digits == 14)
    {
        // invalid 14 digits
        printf("INVALID\n");
    }
    else if (digits == 15)
    {
        // 15 digits
        if (d15 == 3 && (d14 == 4 || d14 == 7))
        {
            if (luhn(cc))
            {
                printf("AMEX\n");
            }
            else
            {
                // invalid not a credit card
                printf("INVALID\n");
            }
        }
        else
        {
            // invalid not American Express
            printf("INVALID\n");
        }
    }
    else if (digits == 16)
    {
        // 16 digits
        if (d16 == 4)
        {
            // VISA
            if (luhn(cc))
            {
                printf("VISA\n");
            }
            else
            {
                // invalid not a credit card
                printf("INVALID\n");
            }
        }
        else if (d16 == 5 && (d15 == 1 || d15 == 2 || d15 == 3 || d15 == 4 || d15 == 5))
        {
            // Mastercard
            if (luhn(cc))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                // invalid not a credit card
                printf("INVALID\n");
            }
        }
        else
        {
            // invalid not VISA or Mastercard
            printf("INVALID\n");
        }
    }
    else
    {
        // invalid >16 digits
        printf("INVALID\n");
    }
}

// Luhns algorithm
bool luhn(long cc)
{
    // Get every digit
    int d1 = cc % 10;
    int d2 = cc % 100 / 10;
    int d3 = cc % 1000 / 100;
    int d4 = cc % 10000 / 1000;
    int d5 = cc % 100000 / 10000;
    int d6 = cc % 1000000 / 100000;
    int d7 = cc % 10000000 / 1000000;
    int d8 = cc % 100000000 / 10000000;
    int d9 = cc % 1000000000 / 100000000;
    int d10 = cc % 10000000000 / 1000000000;
    int d11 = cc % 100000000000 / 10000000000;
    int d12 = cc % 1000000000000 / 100000000000;
    int d13 = cc % 10000000000000 / 1000000000000;
    int d14 = cc % 100000000000000 / 10000000000000;
    int d15 = cc % 1000000000000000 / 100000000000000;
    int d16 = cc % 10000000000000000 / 1000000000000000;

    // Multiply every other digit by 2, add their digits to sumeven. Only when the original digit is 5 or higher do we have 2 digits.
    int sumeven = 0;
    if (d2 > 4)
    {
        sumeven += 1 + (d2 * 2) % 10;
    }
    else
    {
        sumeven += d2 * 2;
    }
    if (d4 > 4)
    {
        sumeven += 1 + (d4 * 2) % 10;
    }
    else
    {
        sumeven += d4 * 2;
    }
    if (d6 > 4)
    {
        sumeven += 1 + (d6 * 2) % 10;
    }
    else
    {
        sumeven += d6 * 2;
    }
    if (d8 > 4)
    {
        sumeven += 1 + (d8 * 2) % 10;
    }
    else
    {
        sumeven += d8 * 2;
    }
    if (d10 > 4)
    {
        sumeven += 1 + (d10 * 2) % 10;
    }
    else
    {
        sumeven += d10 * 2;
    }
    if (d12 > 4)
    {
        sumeven += 1 + (d12 * 2) % 10;
    }
    else
    {
        sumeven += d12 * 2;
    }
    if (d14 > 4)
    {
        sumeven += 1 + (d14 * 2) % 10;
    }
    else
    {
        sumeven += d14 * 2;
    }
    if (d16 > 4)
    {
        sumeven += 1 + (d16 * 2) % 10;
    }
    else
    {
        sumeven += d16 * 2;
    }

    // Add the non multiplied numbers
    int totalsum = sumeven + d1 + d3 + d5 + d7 + d9 + d11 + d13 + d15;

    // return true or false if the final number is modulo 10
    return totalsum % 10 == 0;
}
