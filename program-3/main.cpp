#include "queue.h"
#include <iostream>

/*
    implement radix sort

    notes:
    ------
    input: `input.txt`, one number per line
    
    put data into array as it is read

    nth digit (n=0 for ones): (num / Math.pow(10, n)) % 10

    get max num digits (max n) from largest array element

    each pass: (while n < max) ((n starts at 0, so should end at max-1 to get `max` number of iterations))
        - for each array item, enqueue based on nth digit
        - dequeue in order back into array
        - increase n

    output sorted numbers in columns of 5
*/

int main()
{

}