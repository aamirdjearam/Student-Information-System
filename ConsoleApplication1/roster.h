#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "student.h"

using namespace std;

class Roster
{
private:
    int startingPoint = -1;

    //5 students are provided so we can assume a max student size of 5

    const static int numStudents = 5;

    //This creates an empty array of 5 pointers to hold the data in the student Data Table

    Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };



public:

    //Methods for roster.cpp

    
    Roster();

    void add(string StudentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

    void parse(string data);

    void printCurrentStudents();

    void remove(string studentID);

    void printAll();

    void printByDegreeProgram(DegreeProgram degreeprogram);

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    

     //Destructor
    ~Roster();
};