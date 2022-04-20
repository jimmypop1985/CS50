#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompy user for x
    int x = get_int("x: ");

    //Prompt user for y
    int y = get_int("y: ");

    //Do the addition
    int z = x + y;
    printf("%i\n", z);
}