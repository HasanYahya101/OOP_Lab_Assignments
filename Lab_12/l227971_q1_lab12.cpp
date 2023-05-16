#include <iostream>
using namespace std;

template <class type>

type surprise(type x, type y)
{
    return x + y;
}

int main()
{
    cout << surprise(5, 7) << endl; // the output is: 12

    string str1 = "Sunny";
    string str2 = " Day";
    cout << surprise(str1, str2) << endl; // the output is: Sunny Day

    return 0;
}
