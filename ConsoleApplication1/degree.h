#pragma once
#include <iostream>
#include <string>
using namespace std;
//Including and extra degree program that is UNKNOWN. UNKNOWN is the default Degree Program
enum DegreeProgram
{
    UNKNOWN,
    SECURITY,
    NETWORK,
    SOFTWARE
};

//String version of the Degree Program for print statements
static const string degreeTypeStrings[] = {
    "UNKNOWN",
    "SECURITY",
    "NETWORK",
    "SOFTWARE" };
