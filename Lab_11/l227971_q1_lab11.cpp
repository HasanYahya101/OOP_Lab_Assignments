#include <iostream>
using namespace std;

/*
Answer the following:
a) What is the output if the input is 25 5.50?
Ans: 137.5
b) What is the output if the input is -55 2.8?
Ans: Negative number of items: -55
Number of items must be nonnegative.
c) What is the output if the input is 37 -4.5?
Ans: Negative unit cost: -4.5
Unit cost must be nonnegative.
d) What is the output if the input is -10 -2.5?
Ans: Negative number of items: -10
Number of items must be nonnegative.
*/

int main()
{
    int numOfItems;
    double unitCost;
    try
    {
        cout << "Enter the number of items: ";
        cin >> numOfItems;
        cout << endl;
        if (numOfItems < 0)
            throw numOfItems;
        cout << "Enter the cost of one item: ";
        cin >> unitCost;
        cout << endl;
        if (unitCost < 0)
            throw unitCost;
        cout << "Total cost: $"
             << numOfItems * unitCost << endl;
    }
    catch (int num)
    {
        cout << "Negative number of items: " << num
             << endl;
        cout << "Number of items must be nonnegative."
             << endl;
    }
    catch (double dec)
    {
        cout << "Negative unit cost: " << dec
             << endl;
        cout << "Unit cost must be nonnegative."
             << endl;
    }

    system("pause");

    return 0;
}
