#include <iostream>
using namespace std;

/*
Inline Function (Benifits):
Inline function is called inside the main of a program and it's benifit is that it is very Fast to call the function.
It is better for small functions instead of large functions.
*/

class Operation
{
private:

    int a, b;

public:
    Operation() //default
    {
        a = 5; //default will be 0 in both cases
        b = 5;
    }
    Operation(int x, int y) //overloaded
    {
        a = x;
        b = y;
    }
    void setA(int x) //setter
    {
        cout << "\nSetter A called!\n" << endl;
        a = x;
    }
    void setB(int y) //setter
    {
        cout << "\nSetter B called!\n" << endl;
        b = y;
    }
    int getA() //getter
    {
        cout << "\nGetter A called!\n" << endl;
        return a;
    }
    int getB() //getter
    {
        cout << "\nGetter B called!\n" << endl;
        return b;
    }
    void sum()
    {
        cout << "\nSum is: " << a + b << endl << endl;
    }
    void difference()
    {
        cout << "Difference is: " << a - b << endl << endl;
    }
    void product()
    {
        cout << "Product is: " << a * b << endl << endl;
    }
    void division()
    {
        cout << "Division is: " << a / b << endl << endl;
    }
    ~Operation() //destructor
    {
        cout << "\nDestructor called!\n" << endl;
    }
};

int main()
{
    /*Operation op1(10, 5);
    op1.sum();
    op1.difference();
    op1.product();
    op1.division();*/   //sample
    //write a menu
    int choice1, choice2;
    int x, y;
    Operation op1(x, y);
    do
    {
        cout << "Do you want to use Default Constructor or Overloaded/Parameterised Constructor (x,y)?" << endl;
        cout << "1. Default" << endl;
        cout << "2. Overloaded/Parameterised Constructor" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice1;
        if (choice1 == 1)
        {
            cout << "\nDefault Constructor called\n" << endl;
            Operation op1;
            do
            {
                cout << "1. Sum" << endl;
                cout << "2. Difference" << endl;
                cout << "3. Product" << endl;
                cout << "4. Division" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    op1.sum();
                }
                else if (choice2 == 2)
                {
                    op1.difference();
                }
                else if (choice2 == 3)
                {
                    op1.product();
                }
                else if (choice2 == 4)
                {
                    op1.division();
                }
                else if (choice2 == 5)
                {
                    cout << "\nExiting..." << endl;
                    system("pause");
                    exit(0);
                }
                else
                {
                    cout << "\nInvalid choice. Try again." << endl;
                }
            } while (choice2 != 5);
        }
        else if (choice1 == 2)
        {
            cout << "\nOverloaded/Parameterised Constructor called\n" << endl;
            cout << "Enter value of x: ";
            cin >> x;
            cout << "Enter value of y: ";
            cin >> y;
            while (y == 0)
            {
                cout << "y cannot be 0. Enter y again: ";
                cin >> y;
            }
            Operation op1(x, y);
            cout << "Do you want to use getter/setter to change values of x and y?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Enter your choice: ";
            int choice5;
            cin >> choice5;
            while(choice5 != 1 && choice5 != 2)
            {
                cout << "Invalid choice. Enter again: ";
                cin >> choice5;
            }
            if (choice5 == 1)
            {
                cout << "Enter value of x: ";
                cin >> x;
                cout << "Enter value of y: ";
                cin >> y;
                while (y == 0)
                {
                    cout << "y cannot be 0. Enter y again: ";
                    cin >> y;
                }
                op1.setA(x);
                op1.setB(y);
                x = op1.getA();
                y = op1.getB();
                cout << "x = " << x << endl;
                cout << "y = " << y << endl << endl << endl;
            }
            else if (choice5 == 2)
            {
                cout << "\nUsing default values of x and y" << endl;
            }
            do
            {
                cout << "1. Sum" << endl;
                cout << "2. Difference" << endl;
                cout << "3. Product" << endl;
                cout << "4. Division" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice2;
                if (choice2 == 1)
                {
                    op1.sum();
                }
                else if (choice2 == 2)
                {
                    op1.difference();
                }
                else if (choice2 == 3)
                {
                    op1.product();
                }
                else if (choice2 == 4)
                {
                    op1.division();
                }
                else if (choice2 == 5)
                {
                    cout << "\nExiting..." << endl;
                    system("pause");
                    exit(0);
                }
                else
                {
                    cout << "\nInvalid choice. Try again." << endl;
                }
            } while (choice2 != 5);
        }
        else if (choice1 == 3)
        {
            cout << "\nExiting..." << endl;
            system("pause");
            exit(0);
        }
        else
        {
            cout << "\nInvalid choice. Try again." << endl;
        }
    } while (choice1 != 1 && choice1 != 2);
    system("pause");
    return 0;
}
