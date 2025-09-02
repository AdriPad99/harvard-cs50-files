#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // // promt the user for a height
    // assign the hight variable
    int height;

    do 
    {
        // prompt the user for a pyramid height
        height = get_int("Height: ");

    } while (height < 1); // while height is less than a value of 1

    // // output the pyramid with the given user height
    // for loop through the given user length
    for (int i = 0; i < height; i++)
    {
        // print out spaces equal to the current height - (curr idx + 1)
        for (int j = height - (i + 1); j > 0; j--)
        {
            printf(" ");
        }

        // print out bricks equal to the current parent idx + 1
        for (int j = i + 1; j > 0; j--)
        {
            printf("#");
        }

        // newline to go to next pyramid level
        printf("\n");
    }
}