/**********************************************************************
* Name: Caleb Faruki
* Lab5: Linked List II
* Course: Data Structures
* Date: July 10, 2013
* File: Student Class Implementation
**********************************************************************/
#include "Student.h"

using namespace std;

Student::Student() {
	stuData[0] = "Firstname";
	stuData[1] = "MI";
	stuData[2] = "Lastname";
	stuData[3] = "SSN";
	stuData[4] = "Age";
} // end default constructor

Student::Student(const string & first, const string & mid,
	const string & last, const string & ssn, const string & age) {
	setStudent(first, mid, last, ssn, age);
} // end new constructor

void Student::setStudent( const string& first, const string& mid,
	 const string& last, const string& ssn, const string& age) {
	setName(first, mid, last);
	setSocial(ssn);
	setAge(age);
} // end setStudent()

void Student::setName(const string & first, const string & mid,
	const string & last) {
	stuData[0] = first;
	stuData[1] = mid;
	stuData[2] = last;
} // end setName()

void Student::setSocial(const string & ssn) {
	stuData[3] = ssn;
} // end setSocial()

void Student::setAge(const string & age) {
	stuData[4] = age;
} // end setAge()