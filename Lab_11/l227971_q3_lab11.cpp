#include <iostream>
#include <string>
using namespace std;

class invalidDay
{
public:
    invalidDay() {}
};

class invalidMonth
{
public:
    invalidMonth() {}
};

class invalidYear
{
public:
    invalidYear() {}
};

int main()
{
    int day, month, year;
    string monthName;
    cout << "Enter date of birth in the format MM-DD-YYYY: ";
    cin >> month >> day >> year;

    try
    {
        if (month < 1 || month > 12)
            throw invalidMonth();
        if (day < 1 || day > 31)
            throw invalidDay();
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30)
                throw invalidDay();
        }
        else if (month == 2)
        {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            {
                if (day > 29)
                    throw invalidDay();
            }
            else
            {
                if (day > 28)
                    throw invalidDay();
            }
        }
        if (year < 0)
            throw invalidYear();
    }
    catch (invalidDay)
    {
        cout << "Invalid day entered.\n";
        return 1;
    }
    catch (invalidMonth)
    {
        cout << "Invalid month entered.\n";
        return 1;
    }
    catch (invalidYear)
    {
        cout << "Invalid year entered.\n";
        return 1;
    }

    switch (month)
    {
    case 1:
        monthName = "January";
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    case 5:
        monthName = "May";
        break;
    case 6:
        monthName = "June";
        break;
    case 7:
        monthName = "July";
        break;
    case 8:
        monthName = "August";
        break;
    case 9:
        monthName = "September";
        break;
    case 10:
        monthName = "October";
        break;
    case 11:
        monthName = "November";
        break;
    case 12:
        monthName = "December";
        break;
    }

    cout << monthName << " " << day << ", " << year << endl;
    system("pause");
    return 0;
}