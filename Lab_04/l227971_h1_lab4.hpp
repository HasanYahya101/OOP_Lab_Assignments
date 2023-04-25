#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

class BiggerInt
{
private:
	int* big_int_;
	int int_length_;
public:
	BiggerInt();
	BiggerInt(const int* obj, int size);
	void assign(const BiggerInt& obj);
	void assign(const int* big_int, int size);
	void append(const BiggerInt& obj);
	void append(const int* big_int, int size);
	int compareTo(const BiggerInt& obj);
	int compareTo(const int* big_int, int size);
	void display();
	~BiggerInt();
	/*//create a getter and setter
	int get_int_length() const 
	{ 
		return int_length_; 
	}
	void set_int_length(int int_length) 
	{
		int_length_ = int_length;   //--> Not necessay, but can use if you like
	}
	int* get_big_int() const 
	{ 
		return big_int_; 
	}
	void set_big_int(int* big_int) 
	{ 
		big_int_ = big_int; 
	}
	*/
};

BiggerInt::BiggerInt()
{
	big_int_ = nullptr;
	int_length_ = 0;
}

BiggerInt::BiggerInt(const int* obj, int size)
{
	big_int_ = new int[size];
	for (int i = 0; i < size; i++)
	{
		big_int_[i] = obj[i];
	}
	int_length_ = size;
}

void BiggerInt::assign(const BiggerInt& obj)
{
	int_length_ = obj.int_length_;
	big_int_ = new int[int_length_];
	for (int i = 0; i < int_length_; i++)
	{
		big_int_[i] = obj.big_int_[i];
	}
}

void BiggerInt::assign(const int* big_int, int size)
{
	int_length_ = size;
	big_int_ = new int[int_length_];
	for (int i = 0; i < int_length_; i++)
	{
		big_int_[i] = big_int[i];
	}
}

void BiggerInt::append(const BiggerInt& obj)
{
	int_length_ += obj.int_length_;
	int* temp = new int[int_length_];
	for (int i = 0; i < int_length_; i++)
	{
		temp[i] = big_int_[i];
	}
	for (int i = int_length_ - obj.int_length_; i < int_length_; i++)
	{
		temp[i] = obj.big_int_[i - int_length_ + obj.int_length_];
	}
	delete[] big_int_;
	big_int_ = temp;
}

void BiggerInt::append(const int* big_int, int size)
{
	int_length_ += size;
	int* temp = new int[int_length_];
	for (int i = 0; i < int_length_; i++)
	{
		temp[i] = big_int_[i];
	}
	for (int i = int_length_ - size; i < int_length_; i++)
	{
		temp[i] = big_int[i - int_length_ + size];
	}
	delete[] big_int_;
	big_int_ = temp;
}

int BiggerInt::compareTo(const BiggerInt& obj)
{
	if (int_length_ != obj.int_length_)
	{
		if (int_length_ > obj.int_length_)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		for (int i = 0; i < int_length_; i++)
		{
			if (big_int_[i] != obj.big_int_[i])
			{
				if (big_int_[i] > obj.big_int_[i])
				{
					return 2;
				}
				else
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int BiggerInt::compareTo(const int* big_int, int size)
{
	if (int_length_ != size)
	{
		if (int_length_ > size)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		for (int i = 0; i < int_length_; i++)
		{
			if (big_int_[i] != big_int[i])
			{
				if (big_int_[i] > big_int[i])
				{
					return 2;
				}
				else
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

void BiggerInt::display()
{
	if (big_int_ == nullptr)
	{
		cout << endl << "No Value Assigned, It is a Null ptr!" << endl;
	}
	else
	{
		for (int i = 0; i < int_length_; i++)
		{
			cout << big_int_[i];
		}
		cout << endl;
	}
}

BiggerInt::~BiggerInt()
{
	delete[] big_int_;
}
