#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Degree.h"
#include <string>
using namespace std;

class Student {

public:
	Student(); //empty constructor
	Student(string studentID, string firstName, string lastName, string email, int age, int numDaysInCourse[]); //full constructor
	
	const static int numDaysInCourseSize = 3; //size of array

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumDaysInCourse();
	virtual Degree getDegreeProgram() = 0; //will be overridden

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDaysInCourse(int numDaysInCourse[]);
	virtual void print() = 0; //will be overridden

	~Student(); //deconstructor

private:
	//attributes
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* numDaysInCourse;
	Degree degree;
};
#endif	