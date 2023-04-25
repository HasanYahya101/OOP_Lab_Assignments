#include <iostream>
using namespace std;

class Stat
{
private:
    int size;
    int *array;

public:
    // Default constructor
    Stat() : size(0), array(nullptr) {}

    // Getter
    int getSize() const
    {
        return size;
    }
    // Getter
    int *getArray() const
    {
        return array;
    }

    // Setter
    void setSize(int newSize)
    {
        size = newSize;
    }
    // Setter
    void setArray(int *newArray, int newSize)
    {
        size = newSize;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = newArray[i];
        }
    }
    // destructor
    ~Stat()
    {
        cout << "\nDestructor called." << endl;
        delete[] array;
    }

    // Friend function
    friend double median(Stat obj);
};

double median(Stat obj)
{
    int *tempArray = new int[obj.getSize()];
    for (int i = 0; i < obj.getSize(); i++)
    {
        tempArray[i] = obj.getArray()[i];
    }

    // Sorting the array
    for (int i = 0; i < obj.getSize() - 1; i++)
    {
        for (int j = 0; j < obj.getSize() - i - 1; j++)
        {
            if (tempArray[j] > tempArray[j + 1])
            {
                swap(tempArray[j], tempArray[j + 1]);
            }
        }
    }

    double medianValue;
    if (obj.getSize() % 2 == 0)
    {
        medianValue = (tempArray[obj.getSize() / 2] + tempArray[obj.getSize() / 2 - 1]) / 2.0;
    }
    else
    {
        medianValue = tempArray[obj.getSize() / 2];
    }

    delete[] tempArray;
    return medianValue;
}

int main()
{
    Stat statObj;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    while (size < 2)
    {
        cout << "Size must be greater than 1. Enter again: ";
        cin >> size;
    }

    int *arr = new int[size];
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    statObj.setArray(arr, size);
    cout << "Median: " << median(statObj) << endl;

    delete[] arr;
    system("pause");
    return 0;
}