#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner - does comparisons on score1 and score2 to see which is bigger and reveals the winner, unless they are equal in which case a draw is declared

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0; //intialised the score

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i])) //Converts the word to lowercase if it is uppercase
        {
            word[i] = tolower(word[i]);
        }
        if (word[i] > 96 && word[i] < 123) //Makes sure the current character is a letter
        {
            score += POINTS[word[i] - 'a']; //Updates the score with the value of the current letter
        }
    }
    return score; //returns the score


}
