#include <iostream>
using namespace std;

class Account 
{
protected:
    int accountNumber;
    float accountBalance;

public:
    
    Account(int accountNumber, float accountBalance) 
    {
        this->accountNumber = accountNumber;
        this->accountBalance = accountBalance;
    }
    
    // Getter and Setter for account number
    int getAccountNumber() const 
    {
        return accountNumber;
    }
    void setAccountNumber(int accountNumber) 
    { 
        this->accountNumber = accountNumber; 
    }

    // Getter and Setter for account balance
    float getAccountBalance() const 
    { 
        return accountBalance;
    }
    void setAccountBalance(float accountBalance) 
    { 
        this->accountBalance = accountBalance;
    }

    // Pure virtual functions for Debit and Credit
    virtual void debit(float amount) = 0;
    virtual void credit(float amount) = 0;

    // Virtual Print function
    virtual void print() 
    {
        //nothing here
    }
    
    virtual ~Account()
    {
        cout << "Account destructor called." << endl;
    }
};

class CurrentAccount : public Account 
{
private:
    float serviceCharges;
    float minimumBalance;

public:

    CurrentAccount(int accountNumber, float accountBalance, float serviceCharges, float minimumBalance) : Account(accountNumber, accountBalance) 
    {
        this->serviceCharges = serviceCharges;
        this->minimumBalance = minimumBalance;
    }
    
    // Getter and Setter for service charges
    float getServiceCharges() const 
    { 
        return serviceCharges;
    }
    void setServiceCharges(float serviceCharges) 
    { 
        this->serviceCharges = serviceCharges;
    }

    // Getter and Setter for minimum balance
    float getMinimumBalance() const 
    { 
        return minimumBalance; 
    }
    void setMinimumBalance(float minimumBalance) 
    { 
        this->minimumBalance = minimumBalance;
    }

    // Override Print function
    void print() override 
    {
        cout << "Account Number: " << accountNumber
            << ", Account Balance: " << accountBalance
            << ", Minimum Balance: " << minimumBalance
            << ", Service Charges: " << serviceCharges << endl;
    }

    // Override Debit function
    void debit(float amount) override 
    {
        if (accountBalance >= amount) 
        {
            accountBalance -= amount;
            if (accountBalance < minimumBalance) 
            {
                accountBalance -= serviceCharges;
            }
        }
        else {
            cout << "Insufficient balance." << endl;
        }
    }

    // Override Credit function
    void credit(float amount) override 
    {
        accountBalance += amount;
    }

    ~CurrentAccount() override 
    {
        cout << "CurrentAccount destructor called." << endl;
    }
};

class SavingAccount : public Account 
{
private:
    float interestRate;

public:

    SavingAccount(int accountNumber, float accountBalance, float interestRate) : Account(accountNumber, accountBalance) 
    {
        this->interestRate = interestRate;
    }
    
    // Getter and Setter for interest rate
    float getInterestRate() const 
    { 
        return interestRate;
    }
    void setInterestRate(float interestRate) 
    { 
        this->interestRate = interestRate; 
    }

    // Override Print function
    void print() override {
        cout << "Account Number: " << accountNumber
            << ", Account Balance: " << accountBalance
            << ", Interest Rate: " << interestRate << endl;
    }

    // Override Debit function
    void debit(float amount) override {
        if (accountBalance >= amount) 
        {
            accountBalance -= amount;
        }
        else 
        {
            cout << "Insufficient balance." << endl;
        }
    }

    // Override Credit function
    void credit(float amount) override 
    {
        accountBalance += amount;
    }

    ~SavingAccount() override 
    {
        cout << "SavingAccount destructor called." << endl;
    }
};

int main()
{
    /*Account* account[3];
    //account[0] = new Account(1001, 5000); // error, cannot create an object of virtual class
    account[1] = new CurrentAccount(1002, 8000, 50, 1000);
    account[2] = new SavingAccount(1003, 10000, 5);*/

    //resized the array
    Account* account[2];
    account[0] = new CurrentAccount(1002, 8000, 50, 1000);
    account[1] = new SavingAccount(1003, 10000, 5);

    // Credit and Debit the CurrentAccount and SavingAccount
    account[0]->debit(1000);
    account[1]->credit(500);

    // Print the details of all the accounts
    for (int i = 0; i < 2; i++)
    {
        account[i]->print();
        delete account[i]; // Deallocate memory
        account[i] = nullptr; // Avoid using dangling pointers
    }

    return 0;
}