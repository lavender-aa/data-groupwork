#include <iostream>
#include <string>
#include "set.h"
using std::cout, std::cin, std::endl, std::string;

void print_menu();
int get_menu_choice();
bool valid_choice(char);
void insert(Set);
void search(Set);
void remove(Set);
void display(Set);

int main()
{
    bool quit = false;

    Set set = Set();

    while(!quit) 
    {
        print_menu();
        char choice = get_menu_choice();

        switch(choice) 
        {
            case 'i': 
                insert(set);
                break;
            case 's':
                search(set);
                break;
            case 'r': 
                remove(set);
                break;
            case 'd': 
                display(set);
                break;
            case 'q': 
                quit = true;
                cout << "Exiting.";
                break;
        }
    }

    // set destructor will be called once variable set goes out of scope
}

// --------------------------------- print, menu choice ---------------------------------

void print_menu() 
{
    cout << "Options:" << endl
         << "--------" << endl
         << "\t[i]: insert a new integer into the set" << endl
         << "\t[s]: search for an integer in the set (sets current number)" << endl
         << "\t[r]: remove current number from the set" << endl
         << "\t[d]: display the list" << endl
         << "\t[q]: quit the program" << endl;
}

int get_menu_choice() 
{
    string input = "";

    cout << "Choose an option: ";

    while(!(cin >> input) || cin.peek() != '\n' || !valid_choice(input.at(0)) || input.length() > 1) {
        if(!valid_choice(input.at(0)) || input.length() > 0) {
            cout << "Option " << input << " is not a valid choice.\n\nChoose an option: ";
        }
        else {
            cout << "Invalid input. Enter a character: ";
        }

        cin.clear();

        cin.ignore(3000, '\n');
    }

    // spacing
    cout << endl;

    return input.at(0);
}

bool valid_choice(char choice) 
{
    return choice == 'i' || choice == 's' || choice == 'r' || choice == 'd' || choice == 'q';
}

// --------------------------------- menu functions ---------------------------------

void insert(Set set) 
{

}

void search(Set set)
{

}

void remove(Set set)
{

}

void display(Set set)
{

}