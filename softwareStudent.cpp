#include "SoftwareStudent.h"
#include <iostream>
#include <string>
using namespace std;

SoftwareStudent::SoftwareStudent() :Student() { 

}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int* numDaysInCourse, Degree degreeProgram) { 
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setNumDaysInCourse(numDaysInCourse);
}

Degree SoftwareStudent::getDegreeProgram() { 
	return SOFTWARE;
}
void SoftwareStudent::print() { 
	this->Student::print();
	cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent() {} 

