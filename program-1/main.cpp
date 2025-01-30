#include <iostream>
#include <string>
#include "set.h"
using std::cout, std::endl, std::string;

void print_menu();
int get_menu_choice();

int main()
{
    bool quit = false;

    while(!quit) {
        print_menu();
        int choice = get_menu_choice();
    }
}

void print_menu() {
    cout << "Options:" << endl
         << "--------" << endl
         << "\t[i]: insert a new integer into the set" << endl
         << "\t[s]: search for an integer in the set (sets current number)" << endl
         << "\t[r]: remove current number from the set" << endl
         << "\t[d]: display the list" << endl
         << "\t[q]: quit the program" << endl;
}

