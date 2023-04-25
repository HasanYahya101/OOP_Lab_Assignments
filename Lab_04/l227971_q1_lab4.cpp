#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "l227971_h1_lab4.hpp"

using namespace std;
/*
BiggerInt::BiggerInt()
{
	big_int_ = nullptr;  //==> Using in Header file not in cpp file.
	int_length_ = 0;
}
*/

int main()
{
	cout << "Welcome to the Program, For Evaluation you can simply make a manual input into code" << endl;
	cout << "Or you can use the given MENU!" << endl
		 << endl;
	//-----------------------------------------------------Write Manual Code Here-------------------------------------------------||

	//-----------------------------------------------------Write Manual Code Here-------------------------------------------------||
	int choice = 0;
	do
	{
		cout << "1. Default Constructor --> Task 1" << endl;	// Task 1  ==> Total tasks are 11
		cout << "2. Overloaded Constructor -- Task 2" << endl;	// Task 2
		cout << "3. Assign Function --Task 3 & 4" << endl;		// Task 3 and 4
		cout << "4. Append Function --> Task 5 & 6" << endl;	// Task 5 & 6
		cout << "5. Compare To Function -->Task 7 & 8" << endl; // Task 7 & 8
		cout << "6. Display Function -->Task 9" << endl;		// Task 9
		cout << "7. Exit" << endl;								// Rest is in code
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			BiggerInt obj1;
			obj1.display();
			cout << "Default Constructor done successfully!!!" << endl;
			// destruct object 1
			obj1.~BiggerInt();
			break;
		}
		if (choice == 2)
		{
			int size;
			cout << "Enter the size of the array: ";
			cin >> size;
			while (size <= 0)
			{
				cout << "Invalid size. Please enter a positive integer: ";
				cin >> size;
			}
			int *arr = new int[size];
			cout << "Enter the elements of the array: ";
			for (int i = 0; i < size; i++)
			{
				cin >> arr[i];
			}
			BiggerInt obj2(arr, size);
			obj2.display();
			cout << "Deep Copy done successfully!!!" << endl;
			// destruct object 2
			obj2.~BiggerInt();
			break;
		}
		if (choice == 3)
		{
			int choice2;
			cout << "1. Assign Function with BiggerInt object" << endl;
			cout << "2. Assign Function with integer array" << endl;
			cout << "Enter your choice: ";
			cin >> choice2;
			while (choice2 != 1 && choice2 != 2)
			{
				cout << "Invalid choice. Please enter 1 or 2: ";
				cin >> choice2;
			}
			if (choice2 == 1)
			{
				int size;
				cout << "Enter the size of the array: ";
				cin >> size;
				while (size <= 0)
				{
					cout << "Invalid size. Please enter a positive integer: ";
					cin >> size;
				}
				int *arr = new int[size];
				cout << "Enter the elements of the array: ";
				for (int i = 0; i < size; i++)
				{
					cin >> arr[i];
				}
				BiggerInt obj3(arr, size);
				BiggerInt obj4;
				obj4.assign(obj3);
				obj4.display();
				cout << "Deep Copy done successfully!!!" << endl;
				// destruct object 3 and 4
				obj3.~BiggerInt();
				obj4.~BiggerInt();
				break;
			}
			if (choice2 == 2)
			{
				int size;
				cout << "Enter the size of the array: ";
				cin >> size;
				while (size <= 0)
				{
					cout << "Invalid size. Please enter a positive integer: ";
					cin >> size;
				}
				int *arr = new int[size];
				cout << "Enter the elements of the array: ";
				for (int i = 0; i < size; i++)
				{
					cin >> arr[i];
				}
				BiggerInt obj5;
				obj5.assign(arr, size);
				obj5.display();
				cout << "Deep Copy done successfully!!!" << endl;
				// destruct object 5
				obj5.~BiggerInt();
				break;
			}
		}
		if (choice == 4)
		{
			int choice3;
			cout << "1. Append Function with BiggerInt object" << endl;
			cout << "2. Append Function with integer array" << endl;
			cout << "Enter your choice: ";
			cin >> choice3;
			while (choice3 != 1 && choice3 != 2)
			{
				cout << "Invalid choice. Please enter 1 or 2: ";
				cin >> choice3;
			}
			if (choice3 == 1)
			{
				int size;
				cout << "Enter the size of the array: ";
				cin >> size;
				while (size <= 0)
				{
					cout << "Invalid size. Please enter a positive integer: ";
					cin >> size;
				}
				int *arr = new int[size];
				cout << "Enter the elements of the array: ";
				for (int i = 0; i < size; i++)
				{
					cin >> arr[i];
				}
				BiggerInt obj6(arr, size);
				BiggerInt obj7;
				obj7.append(obj6);
				obj7.display();
				cout << "Append completed Succesfully" << endl;
				// destruct object 6 and 7
				obj6.~BiggerInt();
				obj7.~BiggerInt();
				break;
			}
			if (choice3 == 2)
			{
				int size;
				cout << "Enter the size of the array: ";
				cin >> size;
				while (size <= 0)
				{
					cout << "Invalid size. Please enter a positive integer: ";
					cin >> size;
				}
				int *arr = new int[size];
				cout << "Enter the elements of the array: ";
				for (int i = 0; i < size; i++)
				{
					cin >> arr[i];
				}
				BiggerInt obj8;
				obj8.append(arr, size);
				obj8.display();
				cout << "Append completed Succesfully" << endl;
				// destruct object 8
				obj8.~BiggerInt();
				break;
			}
		}
		if (choice == 5)
		{
			int choice4;
			cout << "You will have to manually give value to check all functionality of (compare to) as the default value is null!!" << endl;
			cout << "1. CompareTo Function with BiggerInt object" << endl;
			cout << "2. CompareTo Function with integer array" << endl;
			cout << "Enter your choice: ";
			cin >> choice4;
			while (choice4 != 1 && choice4 != 2)
			{
				cout << "Invalid choice. Please enter 1 or 2: ";
				cin >> choice4;
			}
			if (choice4 == 1)
			{
				int size;
				cout << "Enter the size of the array: ";
				cin >> size;
				while (size <= 0)
				{
					cout << "Invalid size. Please enter a positive integer: ";
					cin >> size;
				}
				int *arr = new int[size];
				cout << "Enter the elements of the array: ";
				for (int i = 0; i < size; i++)
				{
					cin >> arr[i];
				}
				BiggerInt obj9(arr, size);
				BiggerInt obj10;
				int result = obj10.compareTo(obj9);
				if (result == 0)
				{
					cout << "Equal" << endl;
				}
				else if (result == 1)
				{
					cout << "Less than" << endl;
				}
				else
				{
					cout << "Greater than" << endl;
				}
				cout << "Comparison completed!" << endl;
				// destruct object 9 and 10
				obj9.~BiggerInt();
				obj10.~BiggerInt();
				break;
			}
			if (choice4 == 2)
			{
				int size;
				cout << "Enter the size of the array: ";
				cin >> size;
				int *arr = new int[size];
				cout << "Enter the elements of the array: ";
				for (int i = 0; i < size; i++)
				{
					cin >> arr[i];
				}
				BiggerInt obj11;
				int result = obj11.compareTo(arr, size);
				if (result == 0)
				{
					cout << "Equal" << endl;
				}
				else if (result == 1)
				{
					cout << "Less than" << endl;
				}
				else
				{
					cout << "Greater than" << endl;
				}
				cout << "Comparison Completed Succesfully!" << endl;
				// destruct object 11
				obj11.~BiggerInt();
			}
		}
		if (choice == 6)
		{
			int size;
			cout << "Enter the size of the array: ";
			cin >> size;
			while (size <= 0)
			{
				cout << "Invalid size. Please enter a positive integer: ";
				cin >> size;
			}
			int *arr = new int[size];
			cout << "Enter the elements of the array: ";
			for (int i = 0; i < size; i++)
			{
				cin >> arr[i];
			}
			BiggerInt obj12(arr, size);
			obj12.display();
			cout << "Display completed Succesfully!" << endl;
			// destruct object 12
			obj12.~BiggerInt();
			break;
		}
		if (choice == 7)
		{
			break;
		}
		else
		{
			system("cls");
			cout << "--------------------" << endl;
			cout << "Wrong choice" << endl;
			cout << "--------------------" << endl;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}