#include <iostream>
#include <cstring>
using namespace std;

char** AllocateMemory(int& rows, int& cols)
{
	char** matrix;
	matrix = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new char[cols];
	}
	return matrix;
}

void InputMatrix(char** matrix, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void DisplayMatrix(char** matrix, const int& rows, const int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Separate(char** matrix, const int& rows, const int& cols, char* alphabets, char* numbers, char* specialchar)
{
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z' || matrix[i][j] >= 'a' && matrix[i][j] <= 'z')
			{
				alphabets[a] = matrix[i][j];
				a++;
			}
			else if (matrix[i][j] >= '0' && matrix[i][j] <= '9')
			{
				numbers[b] = matrix[i][j];
				b++;
			}
			else
			{
				specialchar[c] = matrix[i][j];
				c++;
			}
		}
	}
	alphabets[a] = '\0';
	numbers[b] = '\0';
	specialchar[c] = '\0';
}

int main()
{
	int rows, cols;
	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << "Enter the number of columns: ";
	cin >> cols;
	cout << "Enter Elements in the 2D Array!!!" << endl;
	char** matrix = AllocateMemory(rows, cols);
	InputMatrix(matrix, rows, cols);
	DisplayMatrix(matrix, rows, cols);
	char* alphabets = new char[rows * cols];
	char* numbers = new char[rows * cols];
	char* specialchar = new char[rows * cols];
	Separate(matrix, rows, cols, alphabets, numbers, specialchar);
	cout << "Alphabets: " << alphabets << endl;
	cout << "Numbers: " << numbers << endl;
	cout << "Special Characters: " << specialchar << endl;
	system("pause");
	return 0;
}