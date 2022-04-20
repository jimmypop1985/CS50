#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Asks the user for their name and then prints hello, followed by the users input
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}