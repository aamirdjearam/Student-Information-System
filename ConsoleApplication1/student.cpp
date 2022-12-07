#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

//Empty Student Constructor

Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < 3; i++)
        this->numberOfDays[i] = 0;
    this->degree = DegreeProgram::UNKNOWN;
};

//Full Student Constructor

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[], DegreeProgram Degree)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++)
        this->numberOfDays[i] = numberOfDays[i];
    this->degree = Degree;
};

// Getters

string Student::getStudentID()
{
    return this->studentID;
};

string Student::getFirstName()
{
    return this->firstName;
}

string Student::getLastName()
{
    return this->lastName;
}

string Student::getEmailAddress()
{
    return this->emailAddress;
}

int Student::getAge()
{
    return this->age;
}

int* Student::getNumberOfDays()
{
    return this->numberOfDays;
}

DegreeProgram Student::getDegreeProgram()
{
    return this->degree;
}

// Setters

void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string FirstName)
{
    this->firstName = FirstName;
}

void Student::setLastName(string LastName)
{
    this->lastName = LastName;
}

void Student::setEmailAddress(string EmailAddress)
{
    this->emailAddress = EmailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

//Based on the number of days provided in the student data, we can assume only 3 days of course data will ever be provided
void Student::setNumberofDays(int numberOfDays[])
{
    for (int i = 0; i < 3; i++)
        this->numberOfDays[i] = numberOfDays[i];
}

void Student::setDegreeProgram(DegreeProgram selectedDegree)
{
    degree = selectedDegree;
}

// Print Statements (Have been edited to use getter methods to ensure requirments are met [as per CI meeting])

void Student::print()
{
    cout << this->getStudentID() << "\t"
        <<  this->getFirstName() << "\t"
        << this->getLastName() << "\t"
        << this->getAge() << "\t"
        << "{" << this->getNumberOfDays()[0] << "," << this->getNumberOfDays()[1] << "," << this->getNumberOfDays()[2] << "}" << "\t"
        << degreeTypeStrings[this->getDegreeProgram()] << endl;
};

// Destructor

Student::~Student()
{
}