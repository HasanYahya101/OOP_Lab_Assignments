#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
	private:
		string name;
		static int count;
	public:
		Employee(string n)
		{
			name = n;
			count++;
		}
		//return count
		static int getCount()
		{
			return count;
		}
		//destructor
		~Employee()
		{
			count--;
			cout << "Destructor called!" << endl;
		}
};

int Employee::count = 0;

int main()
{
	cout << "1st object Created" << endl;
	Employee a1("Hasan");
	cout << "2nd object Created" << endl;
	Employee a2("Hasan");
	cout << "3rd object Created" << endl;
	Employee a3("Hasan");
	cout << endl;
	cout << "Number of objects created: " << Employee::getCount() << endl << endl;
	system("pause");
	return 0;
}