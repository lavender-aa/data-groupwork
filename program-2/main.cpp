#include <iostream>
#include <stdexcept>
#include <string>
#include "stack.h"
using std::cout, std::endl, std::cin, std::string;

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
int performOperation(int operandA, int operandB, char op);
void evaluatePostfixExpression(Stack& stack, const string& expression);
void clearStack(Stack& stack);

int main()
{


    return 0;
}



// functions
int performOperation(int operandA, int operandB, char op)
{
    switch(op)
    {
        case '+':
            return operandA + operandB;
        case '-':
            return operandA - operandB;
        case '*':
            return operandA * operandB;
        case '/':
            return operandA / operandB;
        default:
            return 0;
    }
}

void evaluatePostfixExpression(Stack& stack, const string& expression)
{
    int charIndex = 0;
    char currentChar = expression[charIndex];
    while(currentChar != '\0')
    {
        // check if current char is a digit
        if(isdigit(currentChar))
        {
            // convert and push the digit onto the stack
            stack.push(currentChar - '0');
        }
        // check if the current char is an operator
        else if(currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/')
        {
            // try to perform the operation
            try
            {
                // pop the top two operands
                int operandB = stack.pop();
                int operandA = stack.pop();

                // perform the operation
                int result = performOperation(operandA, operandB, currentChar);

                // push the result onto the stack
                stack.push(result);
            }
            catch(const std::underflow_error e)
            {
                // print error message and break
                cout << "Invalid expression: " << expression << endl;
                break;
            }
        }
        // invalid expression
        else
        {
            cout << "Invalid postfix expression." << endl;
        }

        // move to the next char
        charIndex++;
        currentChar = expression[charIndex];
    }
}

void clearStack(Stack& stack)
{
    try
    {
        stack.pop();
    }
    catch(const std::underflow_error e)
    {
        return;
    }
    clearStack(stack);
}