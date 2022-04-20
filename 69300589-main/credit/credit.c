#include <stdio.h> //imports the necessary libraries
#include <cs50.h>

int length = 0;  //declares the global variable length

bool check_sum(long card_number)
{
    //function that performs the checksum component of the task with the card number entered and returns true if the sum is valid and false otherwise
    long number = card_number; //declares and initialises the local variavles used in this function
    int first_num = 0;
    int second_num = 0;
    int over_number = 0;

    do
    {
        //doubles every second digit on the card starting from the end, if the doubled number is two digits it adds the two digits together and adds to the other doubled numbers
        //The other digits are added up
        long current_num = number % 10; //isolates the last digit of the card
        int double_number = current_num * 2; //doubles the number and stores as a seperate variable
        if (length % 2 == 0)
        {
            //adds the fist set of numbers together if the current length of the card number is odd (starting from 0)
            first_num += current_num;
        }
        else
        {
            if (double_number / 10 < 1)
            {
                //if the number when doubled is smaller than  10, it can just be added to a subtotal
                second_num += double_number;
            }
            else
            {
                //otherwise if the number when doubled is larger or equal to 10, the digits must be split and added together
                do
                {
                    int first_digit = double_number % 10;
                    double_number /= 10;
                    second_num += first_digit;
                }
                while (double_number >= 1);
            }
        }
        length++; //adds the length
        number = number / 10;
        //divides the card number by 10 so that the next lowest number becomes the smallest for the next iteration
    }
    while (number != 0);
    //repeats the instruction until no numbers are left
    int total = first_num + second_num;
    //adds the totals from the first and second calculations together
    if (total % 10 == 0)
    {
        //if the number ends in a 0 then the card number is valid, otherwise invalid.
        return true;
    }
    else
    {
        return false;
    }
}

int check_type(long card_number) //Checks whether the card is visa, mastercard, amex or invalid
{
    for (int i = 2; i < length; i++) //selects the first two digits of the card number and saves them in a variable
    {
        card_number = card_number / 10;
    }
    if (card_number / 10 == 4 && (length == 16 || length == 13))
        //selects the first card number, checks if its a 4 and checks the length for visa
    {
        return 1;
    }
    if ((card_number > 50 && card_number < 56) && length == 16)
        // checks the parameters for mastercard
    {
        return 2;
    }
    if ((card_number == 37 || card_number == 34) && length == 15)
        //checks the parameters for AMEX
    {
        return 3;
    }
    else
    {
        return 0;
        //Returns 0 which links to an invalid card.
    }
}
int main(void) //prompt for input
{
    long number = get_long("Number?: \n"); //asks user to enter their card details
    bool checksum = check_sum(number);
    //checks the number against the check_sum(number) function declared earlier and assigns the true or false result to a variable
    int checktype = check_type(number);
    //checks the number against the check_type(number) function declared earleir and assigns the returned number (0,1,2 or 3) to a variable
    if (checksum && (checktype == 1))
        //If both conditions are met for VISA then the system output will say VISA
    {
        printf("VISA\n");
    }
    else if (checksum && (checktype == 2))
        //If both conditions for Mastercard are met then the system output will be MASTERCARD
    {
        printf("MASTERCARD\n");
    }
    else if (checksum && (checktype == 3))
        //If both conditions for AMEX are met then the output will be AMEX
    {
        printf("AMEX\n");
    }
    else
    {
        (printf("INVALID\n"));
    }
    //In any other case an INVALID output will appear
}





