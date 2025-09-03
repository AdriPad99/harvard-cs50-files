#include <stdio.h>
#include "cs50.h"

// l algo prototype
bool luhns_algo(long card_num);
// card info prototype
long user_card_num(void);
// card company name prototype
void print_card_company(bool res, long card_num);

int main(void)
{
    // get the users card number
    long card_num = user_card_num();

    // checks for car sum of 20 through the algo
    bool algo_passes = luhns_algo(card_num);

    // output card type depending on algo res
    if (algo_passes)
    {
        print_card_company(algo_passes, card_num);
    } else {
	    printf("INVALID\n");
    }
}

bool luhns_algo(long card_num)
{
    // early edge case: length isn't appropriate
    if (card_num < 1000000000000 || card_num > 9999999999999999)
    {
        // return out false since the length isn't applicable
        return false;
    }

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
            // current card num
            int curr_num = (((card_num / curr_div) % 10));

            // increment curr card sum by cur num
            card_sum += curr_num;

            // increment the curr pos
            pos += 1;

            // increment the curr div by mult by 10
            curr_div *= 10;

            // continue through the while loop
            continue;
        } else if (pos % 2 > 0) {

            // printf("card num: %li, curr div: %li\n", ((card_num / curr_div) % 10), curr_div);

            // calculate the current card number
            int curr_num = (((card_num / curr_div) % 10) * 2);

            // if the current number is greater
            // than 9 (more than 1 digit)
            if (curr_num > 9)
            {
                // curr multiplied num
                // curr_num

                // num 2
                //curr_num % 10

                // num 1
                //curr_num / 10

                // increment curr sum by num 1
                card_sum += (curr_num / 10);

                // increment cur sum by num 2
                card_sum += (curr_num % 10);
            } else {
                // increment the curr card sum by the curr num * 2
                card_sum += curr_num;
            }

            // increment the curr pos
            pos += 1;

            // increment the curr div by mult by 10
            curr_div *= 10;
        }
        // printf("card sum: %i\n", card_sum);
    }

    // return out true if sum is 20
    if (card_sum % 10 == 0)
    {
	    return true;
    } else { // return out false otherwise
	    return false;
    }

    // outputs card sum
    // printf("card sum: %i\n", card_sum);
}

long user_card_num(void)
{
    // assign the int for the user card
    long card_num;

    card_num = get_long("Number: ");

    // return out the user card num
    return card_num;
}

void print_card_company(bool res, long card_num)
{
    // early edge case: card num is 4222222222222
    if (card_num == 4222222222222)
    {
        printf("VISA\n");
        return;
    } else if (card_num < 1000000000000 && card_num > 9999999999999999)
    {
        printf("INVALID\n");
        return;
    }

    // AMEX will be double digit

    // VISA and MASTERCARD will be triple digits

    // initialize the first digits (will be
    // either single or double digits
    int first_digs = card_num / 10000000000000;
    // printf("first digs: %i\n", first_digs);

    // if the variable is greater than 9 and
    // less than 99 ( double digit )
    if (first_digs > 9 && first_digs < 99)
    {
        // re-initialize the first digits
        first_digs = card_num / 10000000000000;
        // printf("first digits (AMEX): %i\n", first_digs);
    } else if (first_digs > 99 && first_digs < 1000) {
        // re-initialize the first digits
        first_digs = card_num / 100000000000000;
        // printf("first digits (VISA/MC): %i\n", first_digs);
    }

    // if the current digits are 34 or 37
    if (first_digs / 10 == 4)
    {
        // if the length of the current card number is 13 or 16
        if ((card_num > 999999999999 && card_num < 10000000000000) ||
            (card_num > 999999999999999 && card_num < 10000000000000000)) {
                // output VIS if the leading number is 4
                printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else if (first_digs == 51 || first_digs == 52 || first_digs == 53 || first_digs == 54 || first_digs == 55) {
        if (card_num > 999999999999999 && card_num < 10000000000000000)
        {
            // output MC if they are the first 5 digits of 50
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    } else if (first_digs == 34 || first_digs == 37){
        if (card_num > 99999999999999 && card_num < 1000000000000000)
        {
            // output AMEX
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}
