#include "NetworkStudent.h"
#include <iostream>
#include <string>
using namespace std;

NetworkStudent::NetworkStudent() :Student() { 

}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int* numDaysInCourse, Degree degreeProgram) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setNumDaysInCourse(numDaysInCourse);
}

Degree NetworkStudent::getDegreeProgram() {
	return NETWORKING;
}
void NetworkStudent::print() {
	this->Student::print();
	cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent() {

}