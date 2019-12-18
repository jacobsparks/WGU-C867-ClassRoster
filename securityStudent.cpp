#include "SecurityStudent.h"
#include <iostream>
#include <string>
using namespace std;

SecurityStudent::SecurityStudent() :Student() {}
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int* numDaysInCourse, Degree degreeProgram) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setNumDaysInCourse(numDaysInCourse);
}

Degree SecurityStudent::getDegreeProgram() {
	return SECURITY;
}
void SecurityStudent::print() {
	this->Student::print();
	cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent() {

}