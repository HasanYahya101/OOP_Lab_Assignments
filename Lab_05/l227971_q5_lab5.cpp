#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	static int totalStudents;
public:
	Student(string name)
	{
		this->name = name;
		totalStudents++;
	}
	Student(const Student& s)
	{
		name = s.name;
		totalStudents++;
	}
	string getName() const
	{
		return name;
	}
	static int getTotalStudents()
	{
		return totalStudents;
	}
	//destructor
	~Student()
	{
		totalStudents--;
		cout << "Destructor Called!!!" << endl;
	}
};

int Student::totalStudents = 0;

int main()
{
	cout << "Creating object s1!!!" << endl;
	Student s1("Hasan");
	cout << endl;
	cout << "Creating object s2!!!" << endl;
	Student s2("Abdullah");
	cout << endl;
	cout << "Creating object s3 using copy Constructor!!!" << endl;
	Student s3(s1);
	cout << endl;
	cout << "Creating constant object!!!" << endl;
	const Student s4("Ahmed");
	cout << endl << endl;
	cout << "Look in the code, changing const gives error!" << endl << endl;
	//s4.name = "Ali";//Error for trying to change constant
	cout << "Calling const get name to display non const name!!!" << endl << endl;
	cout << "Name: " << s4.getName() << endl << endl;
	cout << "Displaying total number of students using static!!!" << endl;
	cout << Student::getTotalStudents() << endl << endl;
	system("pause");
	return 0;
}