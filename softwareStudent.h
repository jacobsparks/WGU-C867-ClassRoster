#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "Student.h"
#include "Degree.h"

using namespace std;

class SoftwareStudent : public Student {
public:
	SoftwareStudent(); //empty constructor
	SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int* numDaysInCourse, Degree degreeProgram); //full constructor
	
	Degree getDegreeProgram(); //overrides base class Student
	void print(); //overrides base class Student
	Degree degreeProgram = SOFTWARE;

	~SoftwareStudent(); //deconstructor
};
#endif