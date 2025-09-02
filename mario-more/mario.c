#include <stdio.h>
#include <cs50.h>

// space prototype
void print_space(int inp, int amnt);
// brick prototype
void print_bricks(int amnt);

int main(void)
{
    // // prompt and get user input

    // assign the pyramid(s) height
    int height;

    // do while to get appropriate pyramid height from the user
    do
    {
        // prompt the user for the pyramid height
        height = get_int("Height: ");
    } while (height < 0 || height > 8); // while the height isn't 0-8 (inclusive)

    // // output the pyramid
    // for loop through the length of the user input
    for (int i = 0; i < height; i++)
    {
        // // left pyramid half

        // print left pyramid space
        print_space(height, i);

        // print left pyramid bricks
        print_bricks(i);

        // print out the empty space between the pyramids
        printf("  ");

        // // right pyramid height

        // print right pyramid bricks
        print_bricks(i);

        // print right pyramid space
        print_space(height, i);

        // print out the newline to go to new pyramid level
        printf("\n");
    }
}

void print_space(int inp, int amnt)
{
    // for loop an amount of space an i amnt less than the user input
    for (int i = inp - (amnt + 1); i > 0; i--)
    {
        // print out an empty space
        printf(" ");
    }
}

void print_bricks(int amnt)
{
    // for loop an amount of bricks equal to the parent idx + 1
    for (int i = amnt + 1; i > 0; i--)
    {
        // print out a brick
        printf("#");
    }
}