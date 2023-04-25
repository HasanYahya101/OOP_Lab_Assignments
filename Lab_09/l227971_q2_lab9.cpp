#include <iostream>
#include <string>

using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    int year;

public:
    void setTitle(const string &title)
    {
        this->title = title;
    }

    void setAuthor(const string &author)
    {
        this->author = author;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    virtual void displayDetails()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

class Book : public LibraryItem
{
private:
    string genre;

public:
    Book(const string &title, const string &author, int year, const string &genre)
    {
        setTitle(title);
        setAuthor(author);
        setYear(year);
        this->genre = genre;
    }

    void displayDetails() override
    {
        LibraryItem::displayDetails();
        cout << "Genre: " << genre << endl;
    }
};

class Journal : public LibraryItem
{
private:
    string subject;

public:
    Journal(const string &title, const string &author, int year, const string &subject)
    {
        setTitle(title);
        setAuthor(author);
        setYear(year);
        this->subject = subject;
    }

    void displayDetails() override
    {
        LibraryItem::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    string publisher;

public:
    Magazine(const string &title, const string &author, int year, const string &publisher)
    {
        setTitle(title);
        setAuthor(author);
        setYear(year);
        this->publisher = publisher;
    }

    void displayDetails() override
    {
        LibraryItem::displayDetails();
        cout << "Publisher: " << publisher << endl;
    }
};

class LibraryPatron
{
private:
    string name;
    LibraryItem *borrowedItems[10];
    int borrowedItemCount = 0;

public:
    LibraryPatron(const string &name)
    {
        this->name = name;
    }

    void borrowItem(LibraryItem *item)
    {
        borrowedItems[borrowedItemCount++] = item;
    }

    void returnItem(LibraryItem *item)
    {
        for (int i = 0; i < borrowedItemCount; i++)
        {
            if (borrowedItems[i] == item)
            {
                borrowedItemCount--;
                for (int j = i; j < borrowedItemCount; j++)
                {
                    borrowedItems[j] = borrowedItems[j + 1];
                }
                break;
            }
        }
    }

    void displayBorrowedItems()
    {
        cout << "Items borrowed by " << name << ":" << endl;
        for (int i = 0; i < borrowedItemCount; i++)
        {
            borrowedItems[i]->displayDetails();
            cout << endl;
        }
    }
};

int main()
{
    // Create LibraryItems
    Book book1("Book 1", "Author 1", 2000, "Fiction");
    Journal journal1("Journal 1", "Author 2", 2010, "Science");
    Magazine magazine1("Magazine 1", "Author 3", 2022, "Publisher 1");

    // Display details of LibraryItems
    cout << "---BOOK---" << endl;
    book1.displayDetails();
    cout << endl;

    cout << "---JOURNAL---" << endl;
    journal1.displayDetails();
    cout << endl;

    cout << "---MAGAZINE---" << endl;
    magazine1.displayDetails();
    cout << endl;

    // Create Library Patron
    LibraryPatron patron1("Patron 1");

    // Borrow Library Items
    patron1.borrowItem(&book1);
    patron1.borrowItem(&journal1);
    patron1.borrowItem(&magazine1);

    // Display Borrowed items by Library Patron
    patron1.displayBorrowedItems();
    cout << endl;

    // Return Library Item
    patron1.returnItem(&journal1);

    // Display Borrowed items by Library Patron after returning an item
    patron1.displayBorrowedItems();
    cout << endl;

    return 0;
}