#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    char op;
    // loops for perform this operation again and again
    do
    {

        // Taking input numbers and operator
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose an operator: ";
        cin >> op;

        switch (op)
        {

        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0)
            {
                cout << "Division by zero is infinity." << endl;
            }
            else
            {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Please enter a valid operator!" << endl;
        }
    } while (1 > 0); // (1 > 0) for running the calculator again and again

    return 0;
}