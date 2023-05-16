#include <iostream>
using namespace std;

template <typename Operation>
Operation performOperation(Operation a, Operation b, char op)
{
    Operation result;
    if (op == '+')
    {
        result = a + b;
    }
    else if (op == '-')
    {
        result = a - b;
    }
    else if (op == '*')
    {
        result = a * b;
    }
    else if (op == '/')
    {
        if (b == 0)
        {
            cout << "Cannot divide by zero" << endl;
            return -1;
        }
        result = a / b;
    }
    else
    {
        cout << "Wrong operation" << endl;
        return -1;
    }
    cout << "Result: " << result << endl;
    return result;
}

int main()
{
    int a, b; // this can be float, int or double too
    char op;
    cout << "Enter first operand: ";
    cin >> a;
    cout << "Enter second operand: ";
    cin >> b;
    cout << "Enter operation: ";
    cin >> op; // op can be +, -, * or /
    if (op == '*' || op == '+' || op == '-' || op == '/')
    {
        performOperation(a, b, op);
    }
    else
    {
        cout << "Wrong operation";
    }

    system("pause");
    return 0;
}