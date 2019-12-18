#include "Degree.h"
#include "Student.h"
#include "Roster.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	const int numStudents = 5;
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
								  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
								  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
								  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
								  "A5,Jacob,Sparks,jspar50@wgu.edu,27,14,23,18,SOFTWARE" };

	cout << "Course: C867 Scripting and Programming - Applications" << endl;
	cout << "Language used: C++" << endl;
	cout << "Student ID: 000833687" << endl;
	cout << "Student Name: Jacob Sparks" << endl;

	Roster* classRoster = new Roster(numStudents);

	cout << "Adding students to the classRoster... " << endl << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseThenAdd(studentData[i]);
	}
	cout << endl;
	cout << "Displaying students ... " << endl << endl;
	classRoster->printAll();
	cout << endl;
	cout << "Displaying invalid emails ... " << endl << endl;
	classRoster->printInvalidEmails();
	cout << endl;
	cout << "Displaying student's average days in course ... " << endl << endl;
	classRoster->printDaysInCourse("A5");
	cout << endl;
	cout << "Displaying student information for the degree program ... " << endl << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	cout << "Removing student A3 ..." << endl << endl;
	classRoster->remove("A3");
	cout << "Trying to remove the same student ..." << endl << endl;
	classRoster->remove("A3");
	classRoster->Roster::~Roster();

	system("pause");
	return 0;
}




Roster::Roster() {
	this->limit = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}
Roster::Roster(int limit) {
	this->limit = limit;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [limit];
}
Roster::~Roster() {}

void Roster::parseThenAdd(string studRow) {
	if (lastIndex < limit) {
		lastIndex++;
		Degree degreeProgram;
		if (studRow[1] == '1') degreeProgram = SECURITY;
		else if (studRow[1] == '2') degreeProgram = NETWORKING;
		else if (studRow[1] == '3') degreeProgram = SOFTWARE;
		else if (studRow[1] == '4') degreeProgram = SECURITY;
		else if (studRow[1] == '5') degreeProgram = SOFTWARE;
		else {
			cout << "INVALID TYPE!" << endl;
			exit(-1);
		}
		int rhs = studRow.find(",");
		string studentID = studRow.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		string firstName = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		string lastName = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		string email = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int age = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int numDaysInCourse1 = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int numDaysInCourse2 = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int numDaysInCourse3 = stoi(studRow.substr(lhs, rhs - lhs));
		add(studentID, firstName, lastName, email, age, numDaysInCourse1, numDaysInCourse2, numDaysInCourse3, degreeProgram);
	}
	else {
		cout << "MAXIMUM CAPACITY REACHED! EXITING NOW ..." << endl;
		exit(-1);
	}
}
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	int day[Student::numDaysInCourseSize];
	day[0] = daysInCourse1;
	day[1] = daysInCourse2;
	day[2] = daysInCourse3;
	if (degreeProgram == NETWORKING) classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, email, age, day, degreeProgram);
	else if (degreeProgram == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, email, age, day, degreeProgram);
	else classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, email, age, day, degreeProgram);
}
void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				classRosterArray[i] = nullptr;
				found = true;
			}
		}
	}
	if (!found) {
		cout << "ERROR! STUDENT NOT FOUND ..." << endl;
	}
}
void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}
void Roster::printDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			int* d = this->classRosterArray[i]->getNumDaysInCourse();
			cout << "Average number of days in three courses for student " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << " days." << endl;
		}
	}
}
void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		string badEmail = classRosterArray[i]->getEmail();
		if ((badEmail.find("@") == -1) || (badEmail.find(".") == -1) || !(badEmail.find(" ") == -1)) {
			cout << badEmail << endl;
		}
	}
}
void Roster::printByDegreeProgram(Degree degreeProgram) {
	Degree tempDegree = degreeProgram;
	for (int i = 0; i < 5; i++) {
		if (tempDegree == classRosterArray[i]->getDegreeProgram()) {
			this->classRosterArray[i]->print();
		}
	}
}

