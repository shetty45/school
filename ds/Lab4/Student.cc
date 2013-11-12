/**********************************************************************
* Name: Caleb Faruki
* Lab4: Basic Linked List
* Course: Data Structures
* Date: July 10, 2013
* File: Student Class Implementation
**********************************************************************/

#include "Student.h"

using namespace std;


Student::Student() {
	stuData[0] = "Firstname";
	stuData[1] = "Middlename";
	stuData[2] = "Lastname";
	stuData[3] = "SSN";
	stuData[4] = "##";
}

Student::Student(const string & first, const string & mid, 
	const string & last, const string & ssn, const string & age) {

	setName(first, mid, last);
	setSocial(ssn);
	setAge(age);
}

void Student::setName(const string & first, const string & mid, 
	const string & last) {

	stuData[0] = first;
	stuData[1] = mid;
	stuData[2] = last;
}

void Student::setSocial(const string & ssn) {
	stuData[3] = ssn;
}

void Student::setAge(const string & age) {
	stuData[4] = age;
}

string Student::getFirst() { return stuData[0]; }

string Student::getMiddle() { return stuData[1]; }

string Student::getLast() { return stuData[2]; }

string Student::getSocial() { return stuData[3]; }

string Student::getAge() { return stuData[4]; }