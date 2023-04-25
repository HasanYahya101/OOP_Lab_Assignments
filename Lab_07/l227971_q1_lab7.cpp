#include <iostream>
using namespace std;

class sterling
{
private:
    long pounds;
    int shillings;
    int pence;

public:
    sterling() // no-argument constructor
    {
        pounds = 0;
        shillings = 0;
        pence = 0;
    }
    sterling(double d) // one-argument constructor, taking type double (for converting from decimal pounds)
    {
        pounds = (long)d;
        shillings = (int)((d - pounds) * 20);
        pence = (int)((((d - pounds) * 20) - shillings) * 12);
        conversion();
    }
    sterling(long p, int s, int pe) // three-argument constructor, taking pounds, shillings, and pence
    {
        pounds = p;
        shillings = s;
        pence = pe;
        conversion();
    }
    void getSterling() // getSterling() to get an amount in pounds, shillings, and pence from the user, format £9.19.11
    {
        char dummy; // to throw away the dots
        cout << "Enter amount (in pounds, shillings, and pence - example/format: 9.19.11): ";
        cin >> pounds >> dummy >> shillings >> dummy >> pence;
        conversion();
    }
    void putSterling() // putSterling() to display an amount in pounds, shillings, and pence, format £9.19.11
    {
        cout << "$" << pounds << "." << shillings << "." << pence << endl;
    }
    sterling operator+(sterling s2) // addition (sterling + sterling) using overloaded + operator
    {
        sterling temp(pounds + s2.pounds, shillings + s2.shillings, pence + s2.pence);
        temp.conversion();
        return temp;
    }
    sterling operator-(sterling s2) // subtraction (sterling - sterling) using overloaded - operator
    {
        sterling temp(pounds - s2.pounds, shillings - s2.shillings, pence - s2.pence);
        temp.conversion();
        return temp;
    }
    sterling operator*(double n) // multiplication (sterling * double) using overloaded * operator
    {
        double total_pounds = (double)(*this);
        total_pounds *= n;
        sterling temp(total_pounds);
        temp.conversion();
        return temp;
    }
    sterling operator/(sterling s2) // division (sterling / sterling) using overloaded / operator
    {
        double total_pounds1 = (double)(*this);
        double total_pounds2 = (double)(s2);
        double result = total_pounds1 / total_pounds2;
        return result;
    }
    sterling operator/(double n) // division (sterling / double) using overloaded / operator
    {
        double total_pounds = (double)(*this);
        total_pounds /= n;
        sterling temp(total_pounds);
        temp.conversion();
        return temp;
    }
    operator double() // operator double (to convert to double)
    {
        double temp;
        temp = pounds + (shillings / 20.0) + (pence / 240.0);
        return temp;
    }
    void conversion() // conversion() to convert any amount of pence into pounds, shillings, and pence
    {
        if (pence >= 12)
        {
            shillings += pence / 12;
            pence %= 12;
        }
        if (shillings >= 20)
        {
            pounds += shillings / 20;
            shillings %= 20;
        }
    }
    ~sterling() // destructor
    {
        cout << "\nDestructor called" << endl;
    }
};

int main()
{
    sterling s1, s2, s3;
    double d;
    s1.getSterling();
    s2.getSterling();
    s3 = s1 + s2;
    cout << "s1 + s2 = ";
    s3.putSterling();
    s3 = s1 - s2;
    cout << "s1 - s2 = ";
    s3.putSterling();
    cout << "Enter a real number: ";
    cin >> d;
    while (d < 1)
    {
        cout << "Enter a real number greater than 0: ";
        cin >> d;
    }
    s3 = s1 * d;
    cout << "s1 * " << d << " = ";
    s3.putSterling();
    sterling s7(10, 20, 30);
    double division_result = s1 / s7;
    cout << "s1 / s3 = " << division_result << endl;
    s3 = s1 / d;
    cout << "s1 / " << d << " = ";
    s3.putSterling();
    d = (double)s1;
    cout << "s1 = " << d << endl;
    system("pause");
    return 0;
}
