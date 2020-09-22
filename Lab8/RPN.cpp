#include <iostream>
#include <string>
#include "Stack.h"

using std::cin, std::cout, std::endl;
using std::string, std::stod;

int main() {
    Stack s;
    while (true) {
        // read a word (token) from input
        string token;
        cin >> token;
        if (isdigit(token[0]) || token[0] == '.') {
            // TODO: use std::stod() to convert token to double
            double element = stod(token);
            // TODO: push operand onto stack
            push(s, element);
            //cout << "Top of Stack when pushing: " << peek(s) << endl;
            //printArray(s);
        } else {

            //cout << "length before operations: " << s.length << endl;
            char c = token[0];
            if (c == '=') {
                break;
            }
            // Otherwise, it should be one of the operators +, -, * /
            // TODO: Pop the value to be the right-hand side of the operator
            //cout << "expected right: " << s.A[s.length - 1] << endl;
            double right = pop(s);
            //cout << "length after popping right: " << s.length << endl;
            //cout << "right: " << right << endl;
            //cout << "Top of Stack after right: " << peek(s) << endl;
            // TODO: Pop the value to be the left-hand side of the operator
            double left = pop(s);
            //cout << "length after popping left: " << s.length << endl;
            //cout << "left: " << right << endl;
            //cout << "Top of Stack after left: " << peek(s) << endl;
            // Do the computation and push the result to the stack
            double val = 0;
            switch (c) {
            case '+':
                // TODO: Do plus, and push the result to the stack
                val = right + left;
                push(s,val);
                //cout << "Top of Stack when adding: " << peek(s) << endl;
                break;
            case '-':
                // TODO: Do minus, and push the result to the stack
                val = left - right;
                push(s,val);
                //cout << "Top of Stack when subtracting: " << peek(s) << endl;
                break;
            case '*':
                // TODO: Do multiplication, and push the result to the stack
                val = right * left;
                push(s,val);
                //cout << "Top of Stack when multiplying: " << peek(s) << endl;
                break;
            case '/':
                // TODO: Do division, and push the result to the stack
                val = left / right;
                push(s,val);
                //cout << "Top of Stack when dividing: " << peek(s) << endl;
                break;
            default:
                cout << "[ERROR] invalid operator: " << c << endl;
                return 1;
            }
        }
    }
    // pop result from stack, and print it to the terminal
    cout << pop(s) << endl;
    
    // free the stack memory
    delete[] s.A;
    
    return 0;
}
