/**********************************************************************
* Name: Caleb Faruki
* Lab5: Linked List II
* Course: Data Structures
* Date: July 17, 2013
* File: Student Class
**********************************************************************/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {

public:
	Student(); //default constructor.
	Student(const string&, const string&, const string&, 
		const string&, const string&); //new constructor.

	//setters
	void setStudent( const string&, const string&, const string&,
		const string&, const string& );
	void setName( const string&, const string&, const string& );
	void setSocial( const string& );
	void setAge( const string& );

	//getters
	string getFirst() {return stuData[0];}
	string getMid() {return stuData[1];}
	string getLast() {return stuData[2];}
	string getSocial() {return stuData[3];}
	string getAge() {return stuData[4];}

private:
	string stuData[5];
};

#endif