#include <cs50.h> //Imports the required libraries
#include <stdio.h>

int main(void)
{

    int answer; //Declares global variable answer
    do
    {
        answer = get_int("How many layers would you like? Please choose an answer between 1 and 8: \n"); //Prompts the user for a number between 1 an 8
    }
    while (answer < 1 || answer > 8); //Prompts once if answer is valid, otherwise keeps asking for answer
    for (int i = 0; i < answer; i++)
    {
        //Creates the number of rows as per the users answer
        for (int j = (answer - 1); j > i ; j--) //prints the blank spaces, starting with one less than the answer and decreasing every row
        {
            printf(" ");
        }
        for (int k = 0; k <= i ; k++)
        {
            //prints the correct number of hashes on the left
            printf("#");
        }
        printf("  "); //prints the two spaces between the left and right hashes
        for (int k = 0; k <= i; k++)
        {
            //prints correct number of hashes on the right
            printf("#");
        }
        printf("\n"); //prints a new line before the program moves on to the next one
    }
}

