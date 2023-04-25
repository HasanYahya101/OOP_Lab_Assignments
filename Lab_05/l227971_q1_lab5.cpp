#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int* id;
public:
	//parameterised constructor
	Student(string name, int id)
	{
		this->name = name;
		this->id = new int;
		*(this->id) = id;
	}
	//copy Constructor
	Student(const Student& obj)
	{
		name = obj.name;
		id = new int;
		*id = *(obj.id);
	}
	//display for checking
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "ID: " << *id << endl;
	}
	//destructor
	~Student()
	{
		delete id;
		cout << "\nDestructor called Succesfully" << endl;
	}
};

int main()
{
	cout << "Defining Object s1 as Hasan with int 10" << endl;
	Student s1("Hasan", 10);
	cout << "Defining Object s2 as Ali with int 20" << endl;
	Student s2("Ali", 20);
	cout << "Copying Object s1 to s3" << endl;
	Student s3(s1);
	cout << "Calling Object s1" << endl;
	s1.display();
	cout << "Calling Object s3" << endl;
	s3.display();
	cout << "Calling Object s2" << endl;
	s3.display();
	system("pause");
	return 0;
}
