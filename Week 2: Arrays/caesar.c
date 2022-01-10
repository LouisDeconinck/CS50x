#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define functions
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Is there only one argument and is it an integer
    if (argc == 2 && only_digits(argv[1]))
    {
        // Convert terminal argument from string to integer
        int k = atoi(argv[1]);

        // Ask for a text to convert
        string text = get_string("plaintext: ");

        printf("ciphertext: ");

        // Go through each character of the plain text and output the new character
        for (int i = 0, l = strlen(text); i < l; i++)
        {
            char new = rotate(text[i], k);
            printf("%c", new);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Check if a string consists out of only digits. Yes = True, No = False
bool only_digits(string s)
{
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Change every character
char rotate(char c, int n)
{
    // If it the character is lowercase
    if (islower(c))
    {
        // Get ASCII
        int position = c;

        // Make a = 0, b = 1, ...
        int order = c - 97;

        // Shift the order of the character and loop every 26 characters
        int neworder = (order + n) % 26;

        // Change the new order to ASCII
        char newchar = neworder + 97;
        return newchar;
    }
    // If it the character is uppercase
    else if (isupper(c))
    {
        // Get ASCII
        int position = c;

        // Make a = 0, b = 1, ...
        int order = c - 65;

        // Shift the order of the character and loop every 26 characters
        int neworder = (order + n) % 26;

        // Change the new order to ASCII
        char newchar = neworder + 65;
        return newchar;
    }
    // If it the character is a different character return as is
    else
    {
        return c;
    }
}
