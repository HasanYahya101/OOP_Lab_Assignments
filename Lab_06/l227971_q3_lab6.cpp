#include <iostream>
using namespace std;

class ComplexNumber
{
private:
	int real;
	int imaginary;
	static int count; //will count the total number of objects created
public:
	ComplexNumber(int, int); //with default arguments
	~ComplexNumber(); //Does Nothing.
	void Input();
	void Output();
	static int countDisplay; //will return the total number of by incrementing as the object is created
	bool IsEqual(ComplexNumber);
	ComplexNumber Conjugate();
	// Adding two complex numbers ( a + bi ) and ( c + di ) yields ( (a+b) + (c+d)i )
	ComplexNumber operator+ (const ComplexNumber & num);
	//Subtracting two complex numbers (a + bi) and (c + di) yields ((a-b) + (c-d)i).
	ComplexNumber operator- (const ComplexNumber & num);
	//Multiplying two complex numbers(a + bi)and(c + di) yields ((ac-bd) + (ad+bc)i).
	ComplexNumber operator* (const ComplexNumber & num);
	//Increment and decrement operators should only add 1 or subtract 1 from real part
	ComplexNumber & operator ++(); // pre-increment
	ComplexNumber & operator --(); // pre-decrement
	ComplexNumber operator ++(int); // post-increment
	ComplexNumber operator --(int); // post-decrement
	bool operator>=(const ComplexNumber& num);
	bool operator<=(const ComplexNumber& num);
	bool operator!=(const ComplexNumber& num);
};

int ComplexNumber::count = 0;
int ComplexNumber::countDisplay = 0;

ComplexNumber::ComplexNumber(int r, int i)
{
	real = r;
	imaginary = i;
	count++;
	countDisplay++;
}
ComplexNumber::~ComplexNumber() //Does Nothing.
{
	//Do Nothing
	/*count--;
    cout << "\nDestructor called!\n" << endl;*/
}
void ComplexNumber::Input()
{
	cout << "Enter real part: ";
	cin >> real;
	cout << "Enter imaginary part: ";
	cin >> imaginary;
}
void ComplexNumber::Output()
{
	cout << real << " + " << imaginary << "i" << endl;
}
bool ComplexNumber::IsEqual(ComplexNumber num)
{
	if (real == num.real && imaginary == num.imaginary)
		return true;
	else
		return false;
}
ComplexNumber ComplexNumber::Conjugate()
{
	ComplexNumber temp(real, -imaginary);
	return temp;
}
ComplexNumber ComplexNumber::operator+(const ComplexNumber & num)
{
	ComplexNumber temp(real + num.real, imaginary + num.imaginary);
	return temp;
}
ComplexNumber ComplexNumber::operator-(const ComplexNumber & num)
{
	ComplexNumber temp(real - num.real, imaginary - num.imaginary);
	return temp;
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber & num)
{
	ComplexNumber temp((real*num.real) - (imaginary*num.imaginary), (real*num.imaginary) + (imaginary*num.real));
	return temp;
}
ComplexNumber & ComplexNumber::operator++()
{
	real++;
	return *this;
}
ComplexNumber & ComplexNumber::operator--()
{
	real--;
	return *this;
}
ComplexNumber ComplexNumber::operator++(int)
{
	ComplexNumber temp(real, imaginary);
	real++;
	return temp;
}
ComplexNumber ComplexNumber::operator--(int)
{
	ComplexNumber temp(real, imaginary);
	real--;
	return temp;
}
bool ComplexNumber::operator>=(const ComplexNumber& num)
{
	if (real >= num.real)
		return true;
	else
		return false;
}
bool ComplexNumber::operator<=(const ComplexNumber& num)
{
	if (real <= num.real)
		return true;
	else
		return false;
}
bool ComplexNumber::operator!=(const ComplexNumber& num)
{
	if (real != num.real)
		return true;
	else
		return false;
}
int main()
{
    cout << "Objects are created!\n\n" << endl; //parameterised constructor
	ComplexNumber c1(1, 2), c2(3, 4), c3(5, 6), c4(7, 8), c5(9, 10);
	cout << endl << endl;
	cout << "Complex Number 1: "; //output function
	c1.Output();
	cout << "Complex Number 2: ";
	c2.Output();
	cout << "Complex Number 3: ";
	c3.Output();
	cout << "Complex Number 4: ";
	c4.Output();
	cout << "Complex Number 5: ";
	c5.Output();
	cout << endl << endl << endl;
	cout << "Inputting values into Complex Number 5" << endl; //input function
	c5.Input();
	cout << "Complex Number 5 now is: ";
	c5.Output();
	cout << "Total number of objects created: " << ComplexNumber::countDisplay << endl << endl;
	cout << endl << endl << endl;
	cout << "Complex Number 1 + Complex Number 2: ";
	(c1 + c2).Output();
	cout << "Complex Number 3 - Complex Number 4: ";
	(c3 - c4).Output();
	cout << "Complex Number 5 * Complex Number 4: ";
	(c5 * c4).Output();
	cout << "\nCreating new complex numbers for further testing\n" << endl;
	ComplexNumber a1(1, 2), a2(3, 4), a3(5, 6), a4(7, 8), a5(9, 10);
	cout << "Complex Number a1: ";
	a1.Output();
	cout << "Complex Number a2: ";
	a2.Output();
	cout << "Complex Number a3: ";
	a3.Output();
	cout << "Complex Number a4: ";
	a4.Output();
	cout << "Complex Number a5: ";
	a5.Output();
	cout << "\n\nTotal number of objects created: " << ComplexNumber::countDisplay << endl;
	cout << "I'm craeting temporary objects (constructor) to use +, -, * etc and have used them 3 times!\n" << endl;
	cout << "Complex Number a1++: ";
	(a1++).Output();
	cout << "New a1: ";
	a1.Output();
	cout << "Complex Number a2--: ";
	(a2--).Output();
	cout << "New a2: ";
	a2.Output();
	cout << "Complex Number ++a3: ";
	(++a3).Output();
	cout << "Complex Number --a4: ";
	(--a4).Output();
	cout << "Complex Number 1 >= Complex Number 2: ";
	if (c1 >= c2)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << "Complex Number 3 <= Complex Number 4: ";
	if (c3 <= c4)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << "Complex Number 5 != Complex Number 1: ";
	if (c5 != c1)
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << "Complex Number 1: ";
	c1.Output();
	cout << "Complex Number 1 conjugate: ";
	c1.Conjugate().Output();
	cout << "Complex Number 2: ";
	c2.Output();
	cout << "Complex Number 2 conjugate: ";
	c2.Conjugate().Output();
	cout << "Complex Number 3: ";
	c3.Output();
	cout << "Complex Number 3 conjugate: ";
	c3.Conjugate().Output();
	cout << "Complex Number 4: ";
	c4.Output();
	cout << "Complex Number 4 conjugate: ";
	c4.Conjugate().Output();
	cout << "Complex Number 5: ";
	c5.Output();
	cout << "Complex Number 5 conjugate: ";
	c5.Conjugate().Output();
	cout << endl << endl << endl;
	cout << "Complex Number 1: ";
	c1.Output();
	cout << "Complex Number 2: ";
	c2.Output();
	cout << "Complex Number 1 == Complex Number 2: ";
	if (c1.IsEqual(c2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << endl << endl << endl;
	cout << "Complex Number 3: ";
	c3.Output();
	cout << "Complex Number 4: ";
	c4.Output();
	cout << "Complex Number 3 == Complex Number 4: ";
	if (c3.IsEqual(c4))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << endl << endl << endl;
	cout << "Complex Number 5: ";
	c5.Output();
	cout << "Complex Number 5 == Complex Number 1: ";
	if (c5.IsEqual(c1))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << endl << endl << endl;
	cout << endl << endl << endl;
	cout << "Creating new object to test for True" << endl;
	ComplexNumber t1(1, 1);
	cout << "Complex Number t1: ";
	t1.Output();
	ComplexNumber t2(1, 1);
	cout << "Complex Number t2: ";
	t2.Output();
	cout << "Complex Number t1 == Complex Number t2: ";
	if (t1.IsEqual(t2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << "\n\nTotal amount of times constructor has been called: " << ComplexNumber::countDisplay << endl << endl;
	cout << endl << endl << endl;
	//end of program
	system("pause");
	return 0;
}