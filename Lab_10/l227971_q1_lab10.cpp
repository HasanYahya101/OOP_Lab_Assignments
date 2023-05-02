#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;

//defining pi value
constexpr auto pi = 3.1415;

class Shape
{
protected:
	string type;
	float area;
	
public:
	virtual void area_calculator() = 0;
	
	Shape()
	{
		type = " ";
		area = 0;
	}
	
	Shape(string type, int area)
	{
		this->type = type;
		this->area = area;
	}
	
	float get_area()
	{
		return area;
	}

	string get_type()
	{
		return type;
	}
};


class Rectangle : public Shape
{
private:
	float height;
	float width;
	float area;
public:
	
	Rectangle()
	{
		height = 0.0;
		width = 0.0;
		area = 0.0;
	}

	Rectangle(float height, float width)
	{
		this->height = height;
		this->width = width;
		area = 0.0;
	}
	
	void area_calculator() override
	{
		// defination
		Shape::type = "Rectangle";
		area = height * width;
		Shape::area = this->area;
	}

};

class Triangle : public Shape
{
private:
	float base;
	float height;
	float area;
	
public:

	Triangle()
	{
		base = 0.0;
		height = 0.0;
		area = 0.0;
	}
	
	Triangle(float base, float height)
	{
		this->base = base;
		this->height = height;
		area = 0.0;
	}

	void area_calculator() override
	{
		// defination
		Shape::type = "Triangle";
		area = 0.5 * base * height;
		Shape::area = this->area;
	}

};


class Circle : public Shape
{
private:
	float radius;
	float area;
	
public:

	Circle()
	{
		radius = 0.0;
		area = 0.0;
	}

	Circle(float radius)
	{
		this->radius = radius;
		this->area = 0.0;
	}

	void area_calculator() override
	{
		Shape::type = "Circle";
		// defination
		this->area = pi * this->radius * this->radius;
		Shape::area = this->area;
	}

};

int main()
{
	Shape* shapes[4];
	shapes[0] = new Rectangle(5, 10);
	shapes[1] = new Triangle(5, 10);
	shapes[2] = new Circle(5);
	shapes[3] = new Circle(10);
	for (int i = 0; i < 4; i++) {
		shapes[i]->area_calculator();
		cout << " area of " << shapes[i]->get_type() << ": " << shapes[i]->get_area() << endl;
	}
	return 0;
}
