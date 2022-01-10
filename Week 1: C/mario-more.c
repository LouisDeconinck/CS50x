#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for pyramid height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (h eight < 1 || height > 8);

    // Variable to store amount of space in front
    int spaces = height - 1;

    // Loop through each level of the pyramid
    for (int i = 0; i < height; i++)
    {
        // Spaces in front
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        spaces--;

        // Pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // To next level
        printf("\n");
    }
}
