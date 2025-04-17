#include "queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cmath>
#define endl "\n"

int getNumDigits(int);
std::string repeatSpace(int);
void radixSort(Queue&, int);

int main()
{
    // open file (closed when goes out of scope by destructor)
    std::ifstream input("input.txt");

    // test if file exists
    if(!input.is_open())
    {
        std::cout << endl << "Input file `input.txt` does not exist." << endl;
        std::cout << "Exiting program." << endl;
        return 0;
    }

    // create queue to hold data
    Queue data;

    // put data into data queue while finding the longest number of digits
    int maxDigits = 0;
    std::string line;
    while(getline(input, line))
    {
        int num = 0;
        try { num = stoi(line); } // get line (number) from file
        catch(std::invalid_argument) { continue; } // skip if invalid

        // adjust max if needed, add to data
        int numDigits = getNumDigits(num);
        if(numDigits > maxDigits) maxDigits = numDigits;
        data.enqueue(num);
    }

    // sort and print the data
    radixSort(data, maxDigits);
    
    // print data in neat columns
    int column = 0;
    while(true)
    {
        try
        {
            // get data into string, print with correct spacing
            std::string num = std::to_string(data.dequeue());
            std::cout << num << repeatSpace(maxDigits - num.length() + 1);

            // move to the next row if we just printed the 5th number
            if(++column % 5 == 0) std::cout << endl;
        }
        catch(std::underflow_error) { break; } // stop once we run out of values
    }

    // make sure the program always ends with a newline
    if(column != 0) std::cout << endl;
}

// returns the number of digits in a number (including negative sign)
int getNumDigits(int num)
{
    int numDigits = (num < 0) ? 1 : 0; // number with a negative sign is one longer
    num = abs(num);
    while(num > 0)
    {
        num /= 10;
        numDigits++;
    }
    return numDigits;
}

// returns a string of repeated spaces
// (slightly cleans up printing section above)
std::string repeatSpace(int numRepeats)
{
    std::string result = "";
    for(int i = 0; i < numRepeats; i++)
        result += " ";
    return result;
}

void radixSort(Queue& data, int maxDigits)
{
        // create digit queues
        Queue queues[10];

        // placeholder for next queue item
        int num;

        int digitNum = 0;
        while(digitNum < maxDigits)
        {
            // sort data from main queue into digit queues
            while(true)
            {
                try { num = data.dequeue(); }
                catch(std::underflow_error) { break; }
                int digit = abs((num / (int)pow(10, digitNum)) % 10);
                queues[digit].enqueue(num);
            }

            // add each digit queue back to data queue in order (0-9)
            for(int i = 0; i < 10; i++)
            {
                while(true)
                {
                    try { num = queues[i].view_back(); }
                    catch(std::underflow_error) { break; }
                    data.enqueue(queues[i].dequeue());
                }
            }

            // move to next digit
            digitNum++;
        }

        // handle negative numbers:

        // separate negatives, get number of negatives
        int count = 0;
        while(true)
        {
            try { num = data.dequeue(); }
            catch(std::underflow_error) { break; }
            if(num < 0)
            {
                count++;
                queues[1].enqueue(num);
            }
            else
                queues[0].enqueue(num);
        }

        // reverse negative number queue using array
        int negatives[count];
        for(int i = count - 1; i >= 0; i--)
        {
            try { negatives[i] = queues[1].dequeue(); }
            catch(std::underflow_error) { break; }
        }

        // put numbers back into data queue (array, queue)
        for(int i = 0; i < count; i++)
            data.enqueue(negatives[i]);
        while(true)
        {
            try { data.enqueue(queues[0].dequeue()); }
            catch(std::underflow_error) { break; }
        }
}