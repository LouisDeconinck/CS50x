#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Initialize functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Ask for text
    string text = get_string("Text: ");

    // Define letters, words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Apply the formula
    float l = (float) letters * 100 / words;
    float s = (float) sentences * 100 / words;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    // Round the index
    int grade = round(index);

    // Grade below 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    // Grade above 16
    else if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", grade);
        return 0;
    }
}

// Get number of letters
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, s = strlen(text); i < s; i++)
    {
        int uppertext = toupper(text[i]);

        if (uppertext > 64 && uppertext < 91)
        {
            letters++;
        }
    }
    return letters;
}

// Get number of words
int count_words(string text)
{
    int words = 1;

    for (int i = 0, s = strlen(text); i < s; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words;
}

// Get number of sentences
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, s = strlen(text); i < s; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}
