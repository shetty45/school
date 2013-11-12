/**********************************************************************
* Name: Caleb Faruki
* Lab4: Basic Linked List
* Course: Data Structures
* Date: July 10, 2013
* File: Student Class
**********************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {

public:
	Student(); //Default constructor;
	Student(const string &, const string &, const string &, 
		const string &, const string &); //New constructor.

	//setters
	void setName(const string &, const string &, const string &);
	void setSocial(const string &);
	void setAge(const string &);

	//getters
	string getFirst();
	string getMiddle();
	string getLast();
	string getSocial();
	string getAge();

private:
	string stuData[5]; //array of fields for Student data.
};

#endif