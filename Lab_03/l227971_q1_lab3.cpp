#include <iostream>
using namespace std;

class Date {
private:
    int Day, Month, Year;

public:
    Date() {
        Day = 1;
        Month = 1;
        Year = 1926;
        cout << "Default Constructor Called" << endl;
    }

    Date(int d, int m, int y) {
        Day = d;
        Month = m;
        Year = y;
    }

    void Print() {
        cout << Day << "/" << Month << "/" << Year << endl;
    }

    void Input() {
        cout << "Enter Day: ";
        cin >> Day;
        cout << "Enter Month: ";
        cin >> Month;
        cout << "Enter Year: ";
        cin >> Year;
    }

    void SetDay(int d) {
        Day = d;
    }

    void SetMonth(int m) {
        Month = m;
    }

    void SetYear(int y) {
        Year = y;
    }

    int GetDay() {
        return Day;
    }

    int GetMonth() {
        return Month;
    }

    int GetYear() {
        return Year;
    }
};

int main() {
    Date date1;
    date1.Print();

    Date date2(10, 2, 2023);
    date2.Print();

    Date xmasDay;
    xmasDay.Print();
    xmasDay.SetDay(25);
    xmasDay.SetMonth(12);
    xmasDay.SetYear(2020);
    xmasDay.Print();

    date1.Input();
    date1.Print();
    system("pause");
    return 0;
}
