#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "Student.h"
#include "Degree.h"

using namespace std;

class SecurityStudent : public Student {
public:
	SecurityStudent(); //empty constructor
	SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int* numDaysInCourse, Degree degreeProgram); //full constructor
	
	Degree getDegreeProgram(); //overrides base class Student
	void print(); //overrides base class Student
	Degree degree = SECURITY;

	~SecurityStudent(); //deconstructor
};
#endif