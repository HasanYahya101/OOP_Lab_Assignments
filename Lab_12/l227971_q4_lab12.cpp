#include <iostream>
#include <cstring>
using namespace std;

// Generic template for increment function
template <typename T>
void increment(T &value)
{
    value += 1;
}

// Template specialization for char* variables
template <>
void increment<char *>(char *&str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] += 1;
    }
}

int main()
{
    int a = 5;
    double b = 3.14;
    float c = 2.5f;
    char s[] = "Assignment 12";
    char *p_s = s;

    increment(a);
    increment(b);
    increment(c);
    increment(p_s);

    cout << "Incremented int: " << a << std::endl;
    cout << "Incremented double: " << b << std::endl;
    cout << "Incremented float: " << c << std::endl;
    cout << "Incremented char array (ASCII values incremented by 1): " << s << std::endl;

    return 0;
}
