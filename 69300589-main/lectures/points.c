#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int points = get_int("How may points did you lose?: ");
    const int mine = 2;

    if (points < mine)
    {
        printf("You lost fewer points than me.\n");
    }
    else if (points > mine)
    {
        printf("You lost more points than me.\n");
    }
    else
    {
        printf("You lost the same number of points as me.\n");
    }
}