#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

class Roster {
private:
	int lastIndex;
	int limit;
	Student** classRosterArray;

public:
	Roster(); //empty constructor
	Roster(int limit); //full constructor
	
	void parseThenAdd(string studRow); //parses strings and updates Roster
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(string studentID); //removes students from roster by ID
	void printAll(); //prints tab-separated list of student data using setter functions
	void printDaysInCourse(string studentID); //prints a student's average number of days in the 3 courses
	void printInvalidEmails(); //prints all invalid emails
	void printByDegreeProgram(Degree degreeProgram); //prints out student information for a degree program specified by the enumerated type

	~Roster(); //deconstructor
};
#endif