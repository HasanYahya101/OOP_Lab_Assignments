#include <iostream>
#include <string>
using namespace std;

class tornadoException
{
private:
    int testing;

public:
    tornadoException()
    {
        testing = 0;
    }
    tornadoException(int m)
    {
        testing = m;
    }
    string print_exception()
    {
        if (testing == 0)
        {
            return "Tornado: Take cover immediately!";
        }
        else
        {
            return "Tornado: " + to_string(testing) + " miles away; and approaching!";
        }
    }
    int get_testing()
    {
        return testing;
    }
};

int main()
{
    tornadoException e1;
    try
    {
        if (e1.get_testing() == 0)
        {
            throw tornadoException();
        }
        else
        {
            throw tornadoException(e1.get_testing());
        }
    }
    catch (tornadoException &e)
    {
        cout << e.print_exception() << endl;
    }

    try
    {
        throw tornadoException(5);
    }
    catch (tornadoException &e)
    {
        cout << e.print_exception() << endl;
    }

    system("pause");
    return 0;
}