#include<iostream>
using namespace std;

class Quadratic
{
    private:

	    int a,b,c;

	public:

		Quadratic()
		{
			a = 0;
			b = 0;
			c = 0;
		}
		Quadratic(int x,int y,int z)
		{
			a = x;
			b = y;
			c = z;
		}
		Quadratic(Quadratic &q)
		{
			a = q.a;
			b = q.b;
			c = q.c;
		}
		~Quadratic()
		{
			cout<<"\nDestructor called\n" << endl;
		}
		Quadratic operator+(Quadratic q) //member function
		{
			Quadratic temp;
			temp.a = a + q.a;
			temp.b = b + q.b;
			temp.c = c + q.c;
			return temp;
		}
		Quadratic operator-(Quadratic q) //member function
		{
			Quadratic temp;
			temp.a = a - q.a;
			temp.b = b - q.b;
			temp.c = c - q.c;
			return temp;
		}
		Quadratic operator*(int x)
		{
			Quadratic temp;
			temp.a = a *x;
			temp.b = b *x;
			temp.c = c *x;
			return temp;
		}

		friend Quadratic operator+(const int& x, const Quadratic& q); //friend function

		friend Quadratic operator-(const int& x, const Quadratic& q); //friend function

		////////////////////////////////////////////

		friend istream& operator>>(istream &in,Quadratic &q);

		friend ostream& operator<<(ostream &out,Quadratic q);

		bool operator==(Quadratic q)
		{
			if(a == q.a && b == q.b && c == q.c)
				return true;
			else
				return false;
		}
		bool operator!=(Quadratic q)
		{
			if(a!=q.a || b!=q.b || c!=q.c)
				return true;
			else
				return false;
		}
		Quadratic operator=(Quadratic q)
		{
			a = q.a;
			b = q.b;
			c = q.c;
			return *this;
		}
};

Quadratic operator-(const int& x, const Quadratic& q)
{
	Quadratic temp;
	temp.a = q.a;
	temp.b = q.b;
	temp.c = q.c - x;
	return temp;
}

Quadratic operator+(const int& x, const Quadratic& q)
{
	Quadratic temp;
	temp.a = q.a;
	temp.b = q.b;
	temp.c = q.c + x;
	return temp;
}

istream& operator>>(istream &in,Quadratic &q)
{
	cout << "\nEnter a,b,c: ";
	in >> q.a >> q.b >> q.c;
	return in;
}
ostream& operator<<(ostream &out,Quadratic q)
{
	out << q.a << "x^2+" << q.b << "x+" << q.c;
	return out;
}

int main()
{
	Quadratic q1, q2, q3, q4, q5, q6;
	cin >> q1;
	cin >> q2;
	q3 = q1 + q2;
	q4 = q1 - q2;
	q5 = q1 * 2;
	cout << "\nq1 = " << q1;
	cout << "\nq2 = " << q2;
	cout << "\nq3 = " << q3;
	cout << "\nq4 = " << q4;
	cout << "\nq5 = " << q5;
	cout << "\nq6 = " << q6;
	cout << "\n\nUse of == operator: " << endl;
	if (q1 == q2)
	{
		cout << "\nq1 and q2 are equal";
	}
	else
	{
		cout << "\nq1 and q2 are not equal";
	}
	cout << endl << endl << endl;
	Quadratic a1, a2;
	cin >> a1;
	cin >> a2;
	cout << "\n\nUse of != operator: " << endl;
	if (a1 != a2)
	{
		cout << "\na1 and a2 are not equal";
	}
	else
	{
		cout << "\na1 and a2 are equal";
	}

	//testing the friend function
	cout << "\n\nTesting the friend function: " << endl;
	q6 = 2 + q1;
	cout << "\nq6 = 2 + q1;" << endl;
	cout << "q6 = " << q6;
	q6 = 2 - q1;
	cout << "\nq6 = 2 - q1;" << endl;
	cout << "q6 = " << q6;
	//end program
	cout << endl << endl;
	system("pause");
	return 0;
}