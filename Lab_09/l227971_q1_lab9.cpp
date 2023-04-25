#include <iostream>
#include <cstring>

using namespace std;

class Person
{
protected:
    int ID;
    char *fName;
    char *lName;
    int age;

public:
    Person(int ID, const char *first_name, const char *last_name, int age)
    {
        cout << "in constructor of class Person" << endl;
        this->ID = ID;
        this->fName = new char[strlen(first_name) + 1];
        strcpy_s(this->fName, strlen(first_name) + 1, first_name);
        this->lName = new char[strlen(last_name) + 1];
        strcpy_s(this->lName, strlen(last_name) + 1, last_name);
        this->age = age;
    }

    virtual ~Person()
    {
        cout << "in destructor of class Person" << endl;
        delete[] fName;
        delete[] lName;
    }

    void print()
    {
        cout << fName << " " << lName << " is " << age << " years old." << endl;
    }

    void input()
    {
        cout << "Enter first name: ";
        char input[100];
        cin >> input;
        delete[] fName;
        fName = new char[strlen(input) + 1];
        strcpy_s(fName, strlen(input) + 1, input);

        cout << "Enter last name: ";
        cin >> input;
        delete[] lName;
        lName = new char[strlen(input) + 1];
        strcpy_s(lName, strlen(input) + 1, input);

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter ID: ";
        cin >> ID;
    }
};

class Student : public Person
{
protected:
    float cgpa;
    char *rollNumber;

public:
    Student(int ID, const char *first_name, const char *last_name, int age, const char *rollNumber, float cgpa)
        : Person(ID, first_name, last_name, age)
    {
        cout << "in constructor of class Student" << endl;
        this->cgpa = cgpa;
        this->rollNumber = new char[strlen(rollNumber) + 1];
        strcpy_s(this->rollNumber, strlen(rollNumber) + 1, rollNumber);
    }

    virtual ~Student()
    {
        cout << "in destructor of class Student" << endl;
        delete[] rollNumber;
    }

    void print()
    {
        Person::print();
        cout << "and his cgpa is " << cgpa << "." << endl;
    }

    void input()
    {
        Person::input();

        cout << "Enter roll number: ";
        char input[100];
        cin >> input;
        delete[] rollNumber;
        rollNumber = new char[strlen(input) + 1];
        strcpy_s(rollNumber, strlen(input) + 1, input);

        cout << "Enter cgpa: ";
        cin >> cgpa;
    }
};

class Undergraduate : public Student
{
private:
    char *fyp_name;

public:
    Undergraduate(int ID, const char *first_name, const char *last_name, int age, const char *rollNumber, float cgpa,
                  const char *fyp_name)
        : Student(ID, first_name, last_name, age, rollNumber, cgpa)
    {
        cout << "in constructor of class Undergraduate" << endl;
        this->fyp_name = new char[strlen(fyp_name) + 1];
        strcpy_s(this->fyp_name, strlen(fyp_name) + 1, fyp_name);
    }

    ~Undergraduate()
    {
        cout << "in destructor of class Undergraduate" << endl;
        delete[] fyp_name;
    }

    void print()
    {
        Student::print();
        cout << "and his final year project is titled " << fyp_name << "." << endl;
    }

    void input()
    {
        Student::input();

        cout << "Enter final year project name: ";
        char input[100];
        cin >> input;
        delete[] fyp_name;
        fyp_name = new char[strlen(input) + 1];
        strcpy_s(fyp_name, strlen(input) + 1, input);
    }
};

class Graduate : public Student
{
private:
    char *thesis_topic;
    char *supervisor_name;

public:
    Graduate(int ID, const char *first_name, const char *last_name, int age, const char *rollNumber, float cgpa,
             const char *thesis_topic, const char *supervisor_name)
        : Student(ID, first_name, last_name, age, rollNumber, cgpa)
    {
        cout << "in constructor of class Graduate" << endl;
        this->thesis_topic = new char[strlen(thesis_topic) + 1];
        strcpy_s(this->thesis_topic, strlen(thesis_topic) + 1, thesis_topic);
        this->supervisor_name = new char[strlen(supervisor_name) + 1];
        strcpy_s(this->supervisor_name, strlen(supervisor_name) + 1, supervisor_name);
    }

    ~Graduate()
    {
        cout << "in destructor of class Graduate" << endl;
        delete[] thesis_topic;
        delete[] supervisor_name;
    }

    void print()
    {
        Student::print();
        cout << "and his thesis topic is " << thesis_topic << ", under supervision of " << supervisor_name << "." << endl;
    }

    void input()
    {
        Student::input();

        cout << "Enter thesis topic: ";
        char input[100];
        cin >> input;
        ChangeInfo(input);

        cout << "Enter supervisor name: ";
        cin >> input;
        delete[] supervisor_name;
        supervisor_name = new char[strlen(input) + 1];
        strcpy_s(supervisor_name, strlen(input) + 1, input);
    }

    void ChangeInfo(const char *thesis_topic)
    {
        delete[] this->thesis_topic;
        this->thesis_topic = new char[strlen(thesis_topic) + 1];
        strcpy_s(this->thesis_topic, strlen(thesis_topic) + 1, thesis_topic);
    }

    void ChangeInfo(const char *thesis_topic, const char *supervisor_name)
    {
        ChangeInfo(thesis_topic);
        delete[] this->supervisor_name;
        this->supervisor_name = new char[strlen(supervisor_name) + 1];
        strcpy_s(this->supervisor_name, strlen(supervisor_name) + 1, supervisor_name);
    }
};

int main()
{
    // create objects and call functions as described in the instructions
    Student *s = new Undergraduate(1, "Ted", "Thompson", 22, "14L-4171", 3.91, "The Event Locator");
    Student *s2 = new Graduate(2, "Arnold", "Gates", 25, "17L-6171", 3.01, "Distributed Algorithms", "Dr Kashif Zafar");

    s->print();
    s->input();
    s2->print();
    s2->input();
    s->print();
    s2->print();
    // The behavior of the p->print() call is due to the fact that the print() function in the Person class is not virtual.
    // As a result, it does not exhibit polymorphic behavior, and the function from the Person class is called
    // instead of the derived classes' print functions.
    // if we turn it to virtual it will give the correct output

    // 4. Create a pointer of Person class which will hold an object from UnderGraduate/Graduate class
    // Person *p = new Undergraduate(1, "Ted", "Thompson", 22, "14L-4171", 3.91, "The Event Locator");

    Person *p = s; // holding an UnderGraduate object
    p->print();    // Notice the output

    // change info of graduate student
    Graduate *grad = dynamic_cast<Graduate *>(s2);
    if (grad)
    {
        // change only thesis topic
        grad->ChangeInfo("New Thesis Topic"); // function overloading

        // change both thesis topic and supervisor name
        grad->ChangeInfo("Another New Thesis Topic", "New Supervisor");
    }

    return 0;
}
