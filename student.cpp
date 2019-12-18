#include "student.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Student::Student() { //sets fields to default values
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->numDaysInCourse = new int[numDaysInCourseSize];
	for (int i = 0; i < numDaysInCourseSize; ++i) this->numDaysInCourse[i] = 0;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysInCourse[]) { //full constructor
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->numDaysInCourse = new int[numDaysInCourseSize];
	for (int i = 0; i < 3; ++i) this->numDaysInCourse[i] = numDaysInCourse[i];
}
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getNumDaysInCourse() {
	return numDaysInCourse;
}
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumDaysInCourse(int numDaysInCourse[]) {
	if (this->numDaysInCourse != nullptr) {
		delete[] this->numDaysInCourse;
		this->numDaysInCourse = nullptr;
	}
	this->numDaysInCourse = new int[numDaysInCourseSize];
	for (int i = 0; i < 3; ++i)
		this->numDaysInCourse[i] = numDaysInCourse[i];
}
void Student::print() {
	cout << "Student ID: " << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age
		<< "\t" << " " << "Days in course: (" << numDaysInCourse[0] << ", " << numDaysInCourse[1] << ", " << numDaysInCourse[2] << ")" << "\t" << "Degree: ";
}
Student::~Student() {}