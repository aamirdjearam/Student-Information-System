#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"

using namespace std;

class Student
{
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numberOfDays[3];
    DegreeProgram degree;

public:
    // Part A1: The Getter Functions

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getNumberOfDays();
    DegreeProgram getDegreeProgram();

    // Part A2: The Setter Functions

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumberofDays(int numberofDays[]);
    void setDegreeProgram(DegreeProgram degree);

    // Print function
    void print();

    // Empty Constructor
    Student();

    // Full Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numberOfDays[3], DegreeProgram Degree);

    // Destructor
    ~Student();
};
