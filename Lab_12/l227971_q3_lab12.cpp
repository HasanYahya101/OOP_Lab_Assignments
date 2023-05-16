#include <iostream>
using namespace std;

template <typename T>
T GetMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
T GetMin(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
T1 GetMax(T1 a, T2 b)
{
    return (a > static_cast<T1>(b)) ? a : static_cast<T1>(b);
}

template <typename T1, typename T2>
T1 GetMin(T1 a, T2 b)
{
    return (a < static_cast<T1>(b)) ? a : static_cast<T1>(b);
}

template <typename T>
T GetMax(T a, T b, T c)
{
    return GetMax(GetMax(a, b), c);
}

template <typename T>
T GetMin(T a, T b, T c)
{
    return GetMin(GetMin(a, b), c);
}
/*
template <typename T>
T GetMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
T GetMin(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
T1 GetMax(T1 a, T2 b)
{
    return (a > static_cast<T1>(b)) ? a : static_cast<T1>(b);
}

template <typename T1, typename T2>
T1 GetMin(T1 a, T2 b)
{
    return (a < static_cast<T1>(b)) ? a : static_cast<T1>(b);
}*/

/*
template <typename T>
T GetMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
T GetMin(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
T1 GetMax(T1 a, T2 b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
T1 GetMin(T1 a, T2 b)
{
    return (a < b) ? a : b;
}
*/

/*
int main()
{
    int i = 5, j = 6, k;
    long l = 10, m = 5, n;
    k = GetMax<int>(i, j);
    n = GetMin<long>(l, m); // The program works fine even if you remove <long> from this line and returns 6 and 5 respectively.
    cout << k << endl;
    cout << n << endl;
    return 0;
}
*/
/*
int main()
{
    char i = 'Z';
    int j = 6, k;
    long l = 10, m = 5, n;
    k = GetMax<int, long>(i, m); // works fine and output is 90 and 6 respectively. even if you remove <int, long> from this line.
    n = GetMin<int, char>(j, l);
    cout << k << endl;
    cout << n << endl;
    system("pause");
    return 0;
}
*/
int main()
{
    char i = 'Z';
    int j = 6, k;
    long l = 10, m = 5, n;
    k = GetMax<int, long>(i, m);
    n = GetMin<int, char>(j, l);
    cout << "Max of i and m: " << k << endl;
    cout << "Min of j and l: " << n << endl;

    int x = 1, y = 4, z = 3;
    cout << "Max of x, y, and z: " << GetMax(x, y, z) << endl; // output is 4
    cout << "Min of x, y, and z: " << GetMin(x, y, z) << endl; // output is 1

    system("pause");
    return 0;
}