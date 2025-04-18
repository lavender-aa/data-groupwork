#include <iostream>
#include <string>
#include "set.h"
using std::cout, std::cin, std::string;

// prototypes
void print_menu();
int get_menu_choice();
bool valid_choice(char);
void insert(Set&);
void search(Set&);
void remove(Set&);
void display(Set&);

int main()
{
    bool quit = false;
    Set set = Set();

    // keep performing operations until the user quits (enters 'q')
    while(!quit) 
    {
        // print, prompt until valid choice entered
        print_menu();
        char choice = get_menu_choice();

        // perform selected choice
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
                cout << "Exiting." << "\n";
                break;
        }
    }

    // set destructor will be called once variable set goes out of scope
}

// --------------------------------- print, menu choice ---------------------------------

void print_menu() 
{
    cout << "Options:" << "\n"
         << "--------" << "\n"
         << "\t[i]: insert a new integer into the set" << "\n"
         << "\t[s]: search for an integer in the set (sets current number)" << "\n"
         << "\t[r]: remove current number from the set" << "\n"
         << "\t[d]: display the list" << "\n"
         << "\t[q]: quit the program" << "\n";
}

int get_menu_choice() 
{
    string input = "";
    cout << "Choose an option: ";

    // if the read fails or bad input is entered, make the user try again until 
    // a good input is received
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
    cout << "\n";

    return input.at(0);
}

bool valid_choice(char choice) 
{
    return choice == 'i' || choice == 's' || choice == 'r' || choice == 'd' || choice == 'q';
}

// --------------------------------- menu functions ---------------------------------

void insert(Set& set) 
{
    int num;

    cout << "Input integer data for new node: ";

    cin >> num;

    void insert(int num);
}

void search(Set& set)
{
    int num;

    cout << "Input integer data to search for: ";

    void search(int num);
}

void remove(Set& set)
{
    void remove_current();
}

void display(Set& set)
{
    void display();
}