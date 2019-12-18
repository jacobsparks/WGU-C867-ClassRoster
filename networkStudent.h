#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "Student.h"
#include "Degree.h"

using namespace std;

class NetworkStudent : public Student {
public:
	NetworkStudent(); //empty constructor
	NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int* numDaysInCourse, Degree degreeProgram); //full constructor
	
	Degree getDegreeProgram(); //overrides base class Student
	void print(); //overrides base class Student
	Degree degreeProgram = NETWORKING;

	~NetworkStudent(); //deconstructor
};
#endif