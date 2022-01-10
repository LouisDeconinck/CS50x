#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define functions
char rotate(char c, string key);

int main(int argc, string argv[])
{
    // If a terminal argument is provided check
    if (argc == 2)
    {
        // for each letter
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // if all characters are letters
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }

            // if all characters are unique
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                if (argv[1][i] == argv[1][j] && i != j)
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }
    }

    // If a correct key is provided
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        //Ask for a text and determine its length
        string text = get_string("plaintext:  ");
        int textlength = strlen(text);

        printf("ciphertext: ");

        // For every character of the text swap it for a new one
        for (int i = 0; i < textlength; i++)
        {
            char new = rotate(text[i], argv[1]);
            printf("%c", new);
        }

        printf("\n");
        return 0;
    }
    // If the key does not have 26 characters
    else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // If incorrect terminal arguments are used
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

// Change every character
char rotate(char c, string key)
{
    // If it the character is lowercase
    if (islower(c))
    {
        // Get ASCII
        int position = c;

        // Make a = 0, b = 1, ...
        int order = c - 97;

        // Assign new character
        char newchar = key[order];

        // Make sure new character is lowercase
        char newlowerchar = tolower(newchar);

        //Return new lowercase charcater
        return newlowerchar;
    }
    // If it the character is uppercase
    else if (isupper(c))
    {
        // Get ASCII
        int position = c;

        // Make a = 0, b = 1, ...
        int order = c - 65;

        // Assign new character
        char newchar = key[order];

        // Make sure new character is uppercase
        char newupperchar = toupper(newchar);

        //Return new uppercase charcater
        return newupperchar;
    }
    // If it the character is a different character return as is
    else
    {
        return c;
    }
}
