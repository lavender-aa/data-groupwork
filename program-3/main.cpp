#include "queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#define endl "\n"
using std::ifstream, std::string, std::stoi;

/*
    implement radix sort

    notes:
    ------
    input: `input.txt`, one number per line

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
    // open file
    ifstream input("input.txt");

    // create digit queues (array of queues)
    Queue data;
    Queue digitQueues[10];

    // put data into data queue (find max)
    int max = 0;
    string line;
    while(getline(input, line))
    {
        int num = 0;
        if(num = stoi(line))
        {

        }
        else
        {

        }
    }

    // close file

    // call radix_sort on number queue (pass queue and max):

        // calculate max_digits

        // digit_num = 0
        // while digit_num < max_digits:
        //      while numq.has_more():
        //          current = dequeue(numq)
        //          digit = get_nth_place_digit(current, n)
        //          queues[digit].enqueue(current)
        // 
        //      for i in range(10):
        //          while queues[i].has_more():
        //              numq.enqueue(queues[i].dequeue())
        // 
        //      digit_num += 1
        // # sorted elems now in numq

        // print in columns of 5 (each with width of max_digits)
}