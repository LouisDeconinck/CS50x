#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for name
    string name = get_string("What's your name? ");

    // Say hello to user
    printf("hello, %s\n", name);
}
