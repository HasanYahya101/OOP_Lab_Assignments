#include <iostream>
using namespace std;

void f3(int num1, int num2)
{
    cout << "Function 3 start" << endl;
    if (num2 == 0)
    {
        throw "Second Number is 0";
    }
    else
    {
        int result = num1 / num2;
        throw result;
    }
    cout << "Function 3 end" << endl;
}

void f2(int num1, int num2)
{
    cout << "Function 2 start" << endl;
    f3(num1, num2);
    cout << "Function 2 end" << endl;
}

void f1(int num1, int num2)
{
    cout << "Function 1 start" << endl;
    f2(num1, num2);
    cout << "Function 1 end" << endl;
}

int main()
{
    cout << "Enter num1: ";
    int num1;
    cin >> num1;
    cout << "Enter num2: ";
    int num2;
    cin >> num2;
    while (num2 < 0)
    {
        cout << "Error, num2 cannot be less than 0: ";
        cin >> num2;
    }
    try
    {
        cout << "Main start" << endl;
        f1(num1, num2);
        cout << "Main end" << endl;
    }
    catch (const char *msg)
    {
        cout << "Catch block: " << msg << endl;
    }
    catch (int result)
    {
        cout << "Catch block: " << result << endl;
    }

    system("pause");
    return 0;
}