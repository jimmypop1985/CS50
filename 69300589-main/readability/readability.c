#include <stdio.h> //Imports the necessary libraries
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);  //declares the prototypes for the functions defined later in the program
int count_words(string text);
int count_sentences(string text);

int main(void)  //takes an input from the user and passes that into functions that return the letter, word and sentence count and calculates the reading grade of the text by applying it to theColeman-Liau fomula
{
    //Prompts user for an input
    string text = get_string("Text: ");

    //Assigns variables to the return values of the functions that calculate the word, letter and sentence count.
    double letters = count_letters(text);
    double words = count_words(text);
    double sentences = count_sentences(text);

    //Calculates the letters per 100 words and sentences per 100 words and stores them in variables
    double l = ((letters / words) * 100);
    double s = ((sentences / words) * 100);

    // The Coleman=Liau formula
    double index = 0.0588 * l - 0.296 * s - 15.8;
    //Rounds the result to an integer
    int grade = round(index);

    //Depending on the grade, the program outputs the result
    if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    //Counts the number of letters in a passed string
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        int lower = tolower(text[i]);
        if (lower > 96 && lower < 123)
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    //Counts the number of words in a string
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string text)
{
    int count = 0;
    //Counts the number of sentences in a passed string
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            count++;
        }
    }
    return count;
}