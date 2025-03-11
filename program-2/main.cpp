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
bool evaluatePostfixExpression(Stack& stack, const string expression);
void clearStack(Stack& stack);
bool validateResult(Stack& stack);



// main
int main()
{


    return 0;
}



// functions
int performOperation(int operandA, int operandB, char op)
{
    switch(op)
    {
        // addition
        case '+':
            return operandA + operandB;
        // subtraction
        case '-':
            return operandA - operandB;
        // multiplication
        case '*':
            return operandA * operandB;
        // division
        case '/':
            return operandA / operandB;
        default:
            return 0;
    }
}

bool evaluatePostfixExpression(Stack& stack, const string expression)
{
    // variables
    int charIndex = 0;
    char currentChar = expression[charIndex];

    // clear the stack
    clearStack(stack);

    // check if the expression is zero length
    if(expression.length() == 0)
    {
        cout << "Invalid expression: No expression" << endl;
        return false;
    }

    // loop through the expression
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
                // expression is invalid, break
                break;
            }
        }
        // invalid expression, return
        else
        {
            cout << "Invalid expression: " << expression << endl;
            return false;
        }

        // move to the next char
        charIndex++;
        currentChar = expression[charIndex];
    }

    // validate the result
    if(!validateResult(stack))
    {
        cout << "Invalid expression: " << expression << endl;
        return false;
    }

    // expression is valid
    return true;
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

bool validateResult(Stack& stack)
{
    try
    {
        int value = stack.pop();
        try
        {
            // stack has more than one element
            stack.pop();
            stack.push(value);
            return false;
        }
        catch (const std::underflow_error e)
        {
            // stack has only one element
            stack.push(value);
            return true;
        }
    }
    catch (const std::underflow_error e)
    {
        // stack is empty
        return false;
    }
}