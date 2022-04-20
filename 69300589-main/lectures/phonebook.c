#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{

    person people[2];
    
    people[0].name = "James";
    people[0].number = "07913";
    people[1].name = "Caroline";
    people[1].number = "07769";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "James") == 0)
        {
            printf("found %s\n", people[i].number);
            return 0;
        }
    }
    printf("not found");
    return 1;
}