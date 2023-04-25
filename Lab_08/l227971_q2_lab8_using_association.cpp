#include <iostream>
#include <string>

using namespace std;

class Author
{
private:
    string name;
    string email;
    char gender;

public:
    Author(const string &name, const string &email, char gender) : name(name), email(email), gender(gender) {}

    string getName() const;

    string getEmail() const;

    void setEmail(const string &email);

    char getGender() const;

    void print() const;
};

string Author::getName() const
{
    return name;
}

string Author::getEmail() const
{
    return email;
}

void Author::setEmail(const string &email)
{
    this->email = email;
}

char Author::getGender() const
{
    return gender;
}

void Author::print() const
{
    cout << name << " (" << gender << ") at " << email << endl;
}

class Book
{
private:
    string name;
    Author author;
    double price;
    int qtyInStock;

public:
    Book(const string &name, const Author &author, double price, int qtyInStock = 0)
        : name(name), author(author), price(price), qtyInStock(qtyInStock) {}

    string getName() const;

    Author getAuthor() const;

    double getPrice() const;

    void setPrice(double price);

    int getQtyInStock() const;

    void setQtyInStock(int qtyInStock);

    void print() const;

    string getAuthorName() const;
};

string Book::getName() const
{
    return name;
}

Author Book::getAuthor() const
{
    return author;
}

double Book::getPrice() const
{
    return price;
}

void Book::setPrice(double price)
{
    this->price = price;
}

int Book::getQtyInStock() const
{
    return qtyInStock;
}

void Book::setQtyInStock(int qtyInStock)
{
    this->qtyInStock = qtyInStock;
}

void Book::print() const
{
    cout << "'" << name << "' by ";
    author.print();
}

string Book::getAuthorName() const
{
    return author.getName();
}

int main()
{
    // Declare and construct an instance of Author
    Author peter("Peter Jones", "peter@somewhere.com", 'm');
    peter.print(); // Peter Jones (m) at peter@somewhere.com

    // Declare and construct an instance of Book
    Book book("C++ for Dummies", peter, 19.99);
    book.print(); // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

    peter.setEmail("peter@xyz.com");
    peter.print(); // Peter Jones (m) at peter@xyz.com
    book.print();  // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

    book.getAuthor().setEmail("peter@abc.com");
    book.print(); // 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

    cout << endl
         << endl
         << endl;
    system("pause");
    return 0;
}