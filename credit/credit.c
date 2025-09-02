#include <stdio.h>
#include <cs50.h>

// l algo prototype
void luhns_algo(long card_num);
// card info prototype
long user_card_num(void);

int main(void)
{
    // get the users card number
    long card_num = user_card_num();

    // TEMP: check for every other num (from left to right)
    luhns_algo(card_num);
}

void luhns_algo(long card_num)
{
    // initialize the mod to find the nums
    long curr_div = 1;

    // initialize the current card sum
    int card_sum = 0;

    // initialize num to keep track of curr position in num
    int pos = 0;
    
    while (curr_div <= 1000000000000000)
    {
        // print out the curr num
        // printf("%li\n", (card_num / curr_div) % 10);

        // if the cur pos mod 2 is == 0
        if (pos % 2 == 0)
        {
            // increment the curr pos
            pos += 1;
            
            // increment the curr div by mult by 10
            curr_div *= 10;
            
            // continue through the while loop
            continue;
        } else if (pos % 2 > 0) {
            
            printf("card num: %li, curr div: %li\n", ((card_num / curr_div) % 10), curr_div);

            // increment the curr card sum by the curr num * 2
            card_sum += (((card_num / curr_div) % 10) * 2);

            // increment the curr pos
            pos += 1;

            // increment the curr div by mult by 10
            curr_div *= 10;
        }
    }

    printf("card sum: %i\n", card_sum);

}

long user_card_num(void)
{
    // assign the int for the user card
    long card_num;

    // do-while to get user input
    do
    {
        card_num = get_long("Number: ");
    } while (card_num < 1000000000000 || card_num > 9999999999999999);
    // it checks while it has an inappropriate amnt of digits

    // return out the user card num
    return card_num;
}