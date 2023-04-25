#include <iostream>
using namespace std;

class Circle
{
private:
	float radius;
	const float pi = 3.14;
public:
	Circle(float r)
	{
		radius = r;
	}
	float getArea() const
	{
		return pi * radius * radius;
	}
	//destructor
	~Circle()
	{
		cout << "\nDestructor called!!!" << endl;
	}
};

int main()
{
	cout << "Giving the constructor a value of 5!!!" << endl << endl;
	Circle c(5.0);
	float f = c.getArea();
	cout << "Area of circle is: " << f << endl;
	system("pause");
	return 0;
}