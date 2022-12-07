#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;


//Parsing function. This uses vector to seperate the information based on the ","
void Roster::parse(string data)
{
    vector<string> parsedInfo;
    size_t startingInt;
    size_t endingInt = 0;
    while ((startingInt = data.find_first_not_of(',', endingInt)) != string::npos)
    {
        endingInt = data.find(',', startingInt);
        parsedInfo.push_back(data.substr(startingInt, endingInt - startingInt));
    }

/* Allocating Degree Type based on ending character of the string.All of them have unique last letters but there are common first letters.
This method would not be effective if there were more degree types as eventually it would cause issues when one of them has the same last letter.*/
    
    DegreeProgram selectedDegree = DegreeProgram::UNKNOWN;
    switch (parsedInfo.at(8).back())
    {
    case 'Y':
        selectedDegree = DegreeProgram::SECURITY;
        break;
    case 'K':
        selectedDegree = DegreeProgram::NETWORK;
        break;
    case 'E':
        selectedDegree = DegreeProgram::SOFTWARE;
        break;
    }

// Adding all of the parsed info together. stoi will be used to convert info from string to integer (age, days to complete course)
    add(
        parsedInfo.at(0),
        parsedInfo.at(1),
        parsedInfo.at(2),
        parsedInfo.at(3),
        stoi(parsedInfo.at(4)),
        stoi(parsedInfo.at(5)),
        stoi(parsedInfo.at(6)),
        stoi(parsedInfo.at(7)),
        selectedDegree);
}

//Adding to the classRosterArray. This method is called in parse
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree)
{
    int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++startingPoint] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degree);
}

//Prints all students and their information
void Roster::printAll()
{
    for (int i = 0; i <= Roster::startingPoint; i++)
    {
        Roster::classRosterArray[i]->print();
    }
    cout << "" << endl;
}

//Print Current Students is a duplicate of the printAll function but without the "Displaying all students text"
void Roster::printCurrentStudents()
{
    cout << "" << endl;
    for (int i = 0; i <= Roster::startingPoint; i++)
    {
        Roster::classRosterArray[i]->print();
    }
    cout << "" << endl;
}

//Print by DegreeProgram checks if the degree program matches the current student and then prints if it does
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    cout << "Showing all students in degree program: " << degreeTypeStrings[degreeprogram] << endl;
    cout << "" << endl;
    for (int i = 0; i <= Roster::startingPoint; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram)
        {
            classRosterArray[i]->print();
        }
    }
    cout << "" << endl;
}

//Print invalid emails checks if the email is invalid by looking for required and invalid characters and then prints if they have/do not have them
void Roster::printInvalidEmails()
{
    cout << "Displaying invalid emails: " << endl;
    cout << "" << endl;
    for (int i = 0; i <= Roster::startingPoint; i++)
    {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
        {
            cout << email << " - is invalid" << endl;
            cout << "" << endl;
        }
    }
}

//Print average students gives the average of the 3 course times provided by the student. This is using int division instead of float. Float can be done by dividing by 3.0 instead of 3
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::startingPoint; i++) 
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << "StudentID: " << classRosterArray[i]->getStudentID() << ", average days in course is : " << (classRosterArray[i]->getNumberOfDays()[0] +
                classRosterArray[i]->getNumberOfDays()[1] +
                classRosterArray[i]->getNumberOfDays()[2]) / 3
                << endl;
        }
    }
}

//Remove checks if the provided remove studentID matches the studentID in the classRosterArray and then removes the student if it matches. It prints the remaining students if the remove was successful and it returns an error message if the remove was unsuccessful.
//Instructions do not state that order matters for remove.
void Roster::remove(string studentID)
{
    bool remove = false;
    cout << "Removing " << studentID << ":" << endl;

    for (int i = 0; i <= Roster::startingPoint; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            remove = true;


            Student* removed = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = removed;

            Roster::startingPoint--;
        }
    }

    if (remove == true)
    {

        this->printAll();
    }

    else
    {
        cout << "" << endl;
        cout << "The student with the ID: " << studentID <<" was not found." << endl;
    }
}

//Empty Constructor
Roster::Roster()
{
}

//Destructor
Roster::~Roster()
{
 
    for (int i = 0; i < numStudents; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    };

}
