#include <stdio.h> //Imports the libraries necessary for the program to function correctly
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])  //Allows command line arguments to be passed into main
{
    //If the first command line argument (CLA) is empty or there is more than one CLA then the  program will stop and an error message will be displayed
    if (argv[1] == NULL || argv[2] != NULL)
    {
        printf("Invaid input\n");
        return 1;
    }
    //Assigns the CLA to a variable
    string cipher = argv[1];

    //Converts the key into lowercase
    for (int i = 0; i < strlen(cipher); i++)
    {
        cipher[i] = tolower(cipher[i]);
    }
    //If the key entered is not the right size, an error message is displayed
    if (strlen(cipher) != 26)
    {
        printf("Key must be 26 characters\n");
        return 1;
    }
    //If any of the chars in the string are not letters an error message is displayed and the program is stopped
    for (int i = 0; i < strlen(cipher); i++)
    {
        if ((cipher[i] < 97) || (cipher[i]) > 122)
        {
            printf("Only letters are valid\n");
            return 1;
        }
    }
    //If there is more than one instance of and particular letter in the string, an error message is displayed and the program is stopped
    for (int i = 0; i < strlen(cipher); i++)
    {
        for (int j = 0; j < strlen(cipher); j++)
        {
            if (cipher[i] == cipher[j] && (i != j))
            {
                printf("Cannot have two matching letters in the cipher\n");
                return 1;
            }
        }
    }

    //Prompts user for their plaintext to be encrypted
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    //alphapet for comparison
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    //If the letter in the plaintext matches a letter in the alphabet then the corresponding letter in the ciphertext will be allocated from the key
    for (int i = 0; i < strlen(plaintext); i++)
    {
        for (int j = 0; j < strlen(alphabet); j ++)
        {
            //makes sure that the case of the original plaintext is kept
            if (tolower(plaintext[i]) > 96 && tolower(plaintext[i]) < 123)
            {
                if (tolower(plaintext[i]) == alphabet[j])
                {
                    if (isupper(plaintext[i]))
                    {
                        printf("%c", toupper(cipher[j]));
                    }
                    else
                    {
                        printf("%c", cipher[j]);
                    }
                }
            }
        }
        //Makes sure any non-letter inputs into the plaintext are left unchanged
        if ((!islower(plaintext[i])) && (!isupper(plaintext[i])))
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}