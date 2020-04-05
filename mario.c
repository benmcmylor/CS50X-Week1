#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        do
        {
            n = get_int("Size: "); //ask user to define height of pyramid
        }
        while (n < 1); //only accept positive integers
    }
    while (n > 8); //define max pyramid height as 8
    for (int i = 0; i < n; i++) //initialize row counter
    {
        for (int j = i + 1; j < n; j++) //intitialize a column counter to print a space in all but the last column
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) //initialize new column counter to print # in last column of row
        {
            printf("#");
        }
        printf("  "); //print two spaces
        for (int j = 0; j < i + 1; j++)//initialize new column counter to print mirror image of #'s
        {
            printf("#");
        }
        printf("\n");
    }
}
