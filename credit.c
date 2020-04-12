#include <stdio.h>
#include <cs50.h>
#include <math.h>

//program to perform basic authentication checks on a credit card number
int main(void)
{
    //initialise long integer to store 16 digit card number
    long cardnum = 0; 
    //initialise integer to store length of card number
    int length = 0;

    //launch do while loop to prompt user to input card number
    do 
    {
        //prompt user to enter card number
        cardnum = get_long("Enter the long number as it appears on the front of your card\nNumber: ");        
        //calculate the number of digits in the card number
        length = log10(cardnum) + 1;
    }
    //reject inputs longer than 16 digits
    while (length > 16); 
   
    //initialise placeholder variable to find first digits of card number
    long first = cardnum;
    //intialise placeholder for verifying the card number is legit
    long num = cardnum;
    //initialaise counters for verifiying card number
    int lastdigit = 0; 
    int digitsum = 0;

    //isolate first two digits of the card number
    while (first >= 99)
    {
        //keep dividing by 10. cardnum stored as int. /10 deletes the last digit
        first /= 10;
    }
    //check if correct length for amex card
    if (length == 15)
    {
        //check if syntax matches amex
        if (first == 34 || first == 37)
        {
            while (num != 0)
            {
                //count the final digit
                digitsum = digitsum + (num % 10);
                //remove last digit to start counting from penultimate number
                num /= 10;
                //isolate the last digit and double it
                lastdigit = (num % 10) * 2;
                //if last double last digit is > 9, split the digits. Otherwise, sum the last digit 
                if (lastdigit > 9)
                {
                    digitsum = (lastdigit % 10) + (lastdigit / 10) + digitsum;
                }
                else
                {
                    digitsum = digitsum + lastdigit;
                }
                //remove the last digit
                num /= 10;
            }
            //printf("Luhn's check = %i\n", digitsum);
            if (digitsum % 10 == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //check if correct length for visa or mastercard
    else if (length == 16)
    {
        //check if syntax matches mastercard
        if (first >= 51 && first <= 55)
        {
            while (num != 0)
            {
                //count the final digit
                digitsum = digitsum + (num % 10);
                //remove last digit to start counting from penultimate number
                num /= 10;
                //isolate the last digit and double it
                lastdigit = (num % 10) * 2;
                //if last double last digit is > 9, split the digits. Otherwise, sum the last digit 
                if (lastdigit > 9)
                {
                    digitsum = (lastdigit % 10) + (lastdigit / 10) + digitsum;
                }
                else
                {
                    digitsum = digitsum + lastdigit;
                }
                //remove the last digit
                num /= 10;
            }
            if (digitsum % 10 == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //check if syntax matches visa
        else if (first / 10 == 4)
        {
            while (num != 0)
            {
                //count the final digit
                digitsum = digitsum + (num % 10);
                //remove last digit to start counting from penultimate number
                num /= 10;
                //isolate the last digit and double it
                lastdigit = (num % 10) * 2;
                //if last double last digit is > 9, split the digits. Otherwise, sum the last digit 
                if (lastdigit > 9)
                {
                    digitsum = (lastdigit % 10) + (lastdigit / 10) + digitsum;
                }
                else
                {
                    digitsum = digitsum + lastdigit;
                }
                //remove the last digit
                num /= 10;
            }
            //printf("Luhn's check = %i\n", digitsum);
            if (digitsum % 10 == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //check if length correct for short visa style and if syntax matches visa
    else if (length == 13 && first / 10 == 4)
    {
        while (num != 0)
        {
            //count the final digit
            digitsum = digitsum + (num % 10);
            //remove last digit to start counting from penultimate number
            num /= 10;
            //isolate the last digit and double it
            lastdigit = (num % 10) * 2;
            //if last double last digit is > 9, split the digits. Otherwise, sum the last digit 
            if (lastdigit > 9)
            {
                digitsum = (lastdigit % 10) + (lastdigit / 10) + digitsum;
            }
            else
            {
                digitsum = digitsum + lastdigit;
            }
            //remove the last digit
            num /= 10;
        }
        //printf("Luhn's check = %i\n", digitsum);
        if (digitsum % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
}
