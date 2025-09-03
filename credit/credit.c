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
    }

    // return out true if sum is 20
    if (card_sum == 20)
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

    // do-while to get user input
    do
    {
        card_num = get_long("Number: ");
    } while (card_num < 1000000000000 || card_num > 9999999999999999);
    // it checks while it has an inappropriate amnt of digits

    // return out the user card num
    return card_num;
}

void print_card_company(bool res, long card_num)
{
    // AMEX will be single digit

    // VISA and MASTERCARD will be double digits

    // initialize the first digits (will be
    // either single or double digits
    int first_digs = card_num / 100000000000000;

    // if the variable is less than 10 and
    // greater than 0 ( single digit )
    if (first_digs > 0 && first_digs < 10)
    {
        // re-initialize the first digits
        first_digs = card_num / 10000000000000;
        printf("first digits: %i\n", first_digs);
    }
}
