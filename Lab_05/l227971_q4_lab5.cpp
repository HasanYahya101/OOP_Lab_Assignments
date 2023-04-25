#include<iostream>
using namespace std;

class Person
{
private:
	string name;
public:
	Person(string n)
	{
		name = n;
	}
	string getname() const
	{
		return name;
	}
	string getName()
	{
		return name;
	}
	//destructor
	~Person()
	{
		cout << "\nDestructor called!!!" << endl;
	}
};

int main()
{
	cout << "Declaring const object p1" << endl;
	const Person p1("Hasan");
	cout << endl;
	cout << "Declaring non-const objects p2 and p3" << endl;
	Person p2("Ahmed");
	Person p3("Ali");
	//p1.name="John";
	cout << "Wrote (cout << p1.getName() << endl;)," << endl;
	cout << "but trying to change a constant object is not allowed!!!" << endl;
	cout << "Error, changing const obj not allowed" << endl;
	cout << "\nPrinting value using constant Function getName!" << endl;
	cout << p2.getName() << endl;
	cout << p3.getName() << endl;
	cout << endl;
	cout << "Printing value using non Constant function getname!" << endl;
	cout << "cout << p1.getname() << endl;" << " ,This is not allowed!" << endl;
	cout << "Error, this is not allowed!!!" << endl;
	cout << endl;
	//use const_cast
	cout << "Using const_cast to change the value of a constant object!!!" << endl;
	//use const_cast
	Person* p = const_cast<Person*>(&p1);
	//call the non-constant function
	cout << "Calling Non ConstantMember Function!!!   -(Hurray)" << endl;
	cout << "Name: " << p->getName();
	cout << endl << endl << endl;
	cout << "However, if we access it using a constant member function, then we can access it:" << endl;
	cout << "Name of Constant Object using Constant function: " << p1.getname() << endl << endl;
	system("pause");
	return 0;
}