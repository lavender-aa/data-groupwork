#include <iostream>
#include <stdexcept>
#include "stack.h"
using std::cout, std::endl, std::cin;

/*

notes:

<stdexcept> is required for detecting stack underflows;
you can check out how they're thrown in Stack::pop() and Stack::view_top().

not exactly sure if Sible expects us to use this, but we can ask about it next class

c++ has the usual `try` and `catch` blocks. 
to catch the underflow error thrown by pop() and view_top():

    ```
    try {
        // some code involving pop() or view_top()
    }
    catch (std::underflow_exception err) {
        // handle error
        // the specific error message is returned by `err.what()` (const char*)
    }
    ```


i put some testing stuff in here to more easily prove that everything works as it should.
all testing stuff below main() should be removed once the pr is approved (before merging)

*/

// prototypes
// TODO: remove tests
void run_tests();
void test1();
void test2();
void test3();


int main()
{
    run_tests();
}



// testing methods
// TODO: remove
#include <cassert>
#include <cstring>

void run_tests() {
    test1();
    test2();
    test3();
}

// test popping, viewing empty stack
void test1() {
    cout << "test 1: pop and view empty stack\n";

    Stack stack = Stack();

    try {
        stack.pop();
    }
    catch (std::underflow_error err) {
        assert((std::string)err.what() == "Attempted to pop empty stack.");
    }

    try {
        cout << stack.view_top() << "\n";
    }
    catch (std::underflow_error err) {
        assert((std::string)err.what() == "Attempted to view top of empty stack.");
    }

    cout << "test 1 passed.\n\n";
}

// test filing stack, view top, and popping
void test2() {
    cout << "test 2: fill and empty stack\n";

    Stack stack = Stack();

    // ensure value returned from stack_top() matches value inserted
    for(int i = 0; i < 5; i++) {
        stack.push(i);
        assert(stack.view_top() == i);
    }

    // ensure value returned from pop() matches value inserted
    for(int i = 4; i >= 0; i--) {
        int num = stack.pop();
        assert(num == i);
    }

    cout << "test 2 passed.\n\n";
}

// test filling then emptying stack too far
void test3() {
    cout << "test 3: fill, empty stack too far\n";

    Stack stack = Stack();

    // fill stack with 0-9
    for(int i = 0; i < 10; i++) {
        stack.push(i);
    }

    // pop stack 11 times
    for(int i = 0; i < 11; i++) {
        try {
            stack.pop();
            assert(i != 10); // 11th pop should fail
        }
        catch (std::underflow_error err) {
            assert((std::string)err.what() == "Attempted to pop empty stack.");
            assert(i == 10);
        }
    }

    cout << "test 3 passed.\n\n";
}