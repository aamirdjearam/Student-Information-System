
#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main()
{
    //Inserting the provided Student Data
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Aamir,Djearam,adjear1@wgu.edu,21,20,30,40,SOFTWARE" 
    };

    // Entering the Assignment Information
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 009101364" << endl;
    cout << "Name: Aamir A Djearam" << endl;
    cout << "" << endl;

    //Creating the Roster item
    Roster classRoster;

    //Parsing the Student Data. There are 9 data items per student so every 9 data items is a new student.
    for (int i = 0; i < (sizeof(classRoster)/9); i++)
    {
        classRoster.parse(studentData[i]);
    }
    
    //Displaying all students
    cout << "Displaying all Students: " << endl;
    classRoster.printAll();

    //Displaying all incorrect emails
    classRoster.printInvalidEmails();

    //Displaying the average days in courses for all students using a for loop as per requirements
    for (int i = 0; i < (sizeof(classRoster) / 9 + 1); i++)
    {
        string currentStudent = ("A" + to_string(i));
        classRoster.printAverageDaysInCourse(currentStudent);
    }

    // Blank space to match the example output image
    cout << endl;

    // Printing all students with the "Software" degree type using the printByDegreeProgram command
    classRoster.printByDegreeProgram(SOFTWARE);

    //Removing student A3 to demonstrate proper removal
    //This prints all remaining students. There is no instructions stating that the order must be the same
    classRoster.remove("A3");

    //Removing student A3 to demonstrate failed removal
    classRoster.remove("A3");


    cout << "DONE. " << endl;

 
    return 0;
}
