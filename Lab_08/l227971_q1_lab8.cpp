#include <iostream>
#include <string>
using namespace std;

class Time
{
private:
    int hr;
    int min;

public:
    Time();
    Time(int, int);
    void setTime(int, int);
    void getTime(int &, int &);
    void printTime();
    void incrementHours();
    void incrementMinutes();
};

Time::Time() : hr(0), min(0) {}

Time::Time(int h, int m)
{
    setTime(h, m);
}

void Time::setTime(int h, int m)
{
    hr = h;
    min = m;
}

void Time::getTime(int &h, int &m)
{
    h = hr;
    m = min;
}

void Time::printTime()
{
    if (hr < 10 && min > 10)
    {
        cout << "0" << hr << ":" << min;
    }
    else if (hr > 10 && min < 10)
    {
        cout << hr << ":0" << min;
    }
    else if (hr < 10 && min < 10)
    {
        cout << "0" << hr << ":0" << min;
    }
    else
    {
        cout << hr << ":" << min;
    }
}

void Time::incrementHours()
{
    hr++;
}

void Time::incrementMinutes()
{
    min++;
}

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int, int, int);
    void setDate(int, int, int);
    void getDate(int &, int &, int &);
    void printDate();
};

Date::Date() : month(1), day(1), year(1900) {}

Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

void Date::setDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::getDate(int &m, int &d, int &y)
{
    m = month;
    d = day;
    y = year;
}

void Date::printDate()
{
    if (month < 10 && day < 10)
    {
        cout << "0" << month << "/0" << day << "/" << year;
    }
    else if (month < 10 && day > 10)
    {
        cout << "0" << month << "/" << day << "/" << year;
    }
    else if (month > 10 && day < 10)
    {
        cout << month << "/0" << day << "/" << year;
    }
    else
    {
        cout << month << "/" << day << "/" << year;
    }
}

class Event
{
private:
    string eventName;
    Time eventTime;
    Date eventDay;

public:
    Event(int hours = 0, int minutes = 0, int m = 1,
          int d = 1, int y = 1900, string name = "Christmas");
    void setEventData(int hours, int minutes, int m, int d, int y, string name);
    void printEventData();
};

Event::Event(int hours, int minutes, int m, int d, int y, string name)
{
    setEventData(hours, minutes, m, d, y, name);
}

void Event::setEventData(int hours, int minutes, int m, int d, int y, string name)
{
    eventName = name;
    eventTime.setTime(hours, minutes);
    eventDay.setDate(m, d, y);
}

void Event::printEventData()
{
    cout << "Event Name: " << eventName << endl;
    cout << "Event Time: ";
    eventTime.printTime();
    cout << endl;
    cout << "Event Date: ";
    eventDay.printDate();
    cout << endl;
}

int main()
{
    // instantiate an object and set data for Christmas
    Event object;
    object.setEventData(6, 0, 12, 25, 2010, "Christmas");
    // print out the data for object
    object.printEventData();

    // instantiate the second object and set date for the fourth of July
    Event object2;
    object2.setEventData(1, 15, 7, 4, 2010, "Fourth of July");
    // print out the data for the second object
    object2.printEventData();

    cout << endl
         << endl
         << endl;
    system("pause");
    return 0;
}
