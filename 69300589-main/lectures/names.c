#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names [] = {"James","Caroline","Iain","Val","Spoon","Andy","Rufus"};
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Iain") == 0)
        {
            printf("found\n");
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}