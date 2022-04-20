#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int preferences[10][10];
    for(int i = 0; i <10; i++)
    {
        string input = get_string("N: ");
        for(int j = 1; j <=10; j++)
        {
            printf("%i\n", preferences[i][j]++);
            preferences[i][j]++;
        }
    }
}