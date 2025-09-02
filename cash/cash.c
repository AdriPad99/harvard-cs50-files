#include <stdio.h>
#include <cs50.h>

// change prototype
int user_change(void);
// returned change prototype
void print_returned_coin_amnt(int change_amnt);

int main(void)
{
    // get the change from the user
    int change = user_change();

    // print out the amount of change in coins
    print_returned_coin_amnt(change);
}

int user_change(void)
{
    // assign the int for the change
    int change;
    
    // do-while to get appropriate change
    do
    {
        // prompt the user for an amount of change
        change = get_int("Change owed: ");
    } while (change < 1); // while the change amount is less than 1

    // return out the users input change
    return change;
}

void print_returned_coin_amnt(int change_amnt)
{
    // initialize the amnt of coins
    int coins = 0;

    // increment the amnt of coins by the current argument / 25
    coins += change_amnt / 25;

    // modulo the argument by 25
    change_amnt %= 25;

    // increment the amnt of coins by the curr argument / 10
    coins += change_amnt / 10;

    // modulo the arg by 10
    change_amnt %= 10;

    // increment the amnt of coins by the curr arg / 5
    coins += change_amnt / 5;

    // modulo the arg by 5
    change_amnt %= 5;

    // increment the coins by the current remaining arg
    coins += change_amnt;

    // print out the current amnt of coins
    printf("%i\n", coins);
}