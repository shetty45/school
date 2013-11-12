/**********************************************************************
* Name: Caleb Faruki
* Lab4: Basic Linked List
* Course: Data Structures
* Date: July 10, 2013
* File: Node Class
**********************************************************************/

/*=============================NODE===================================*
 |			  DATA 				|				NEXT 				  |
 |====================================================================*
*/
#ifndef NODE_H
#define NODE_H

#include "Student.h"
#include <iostream>

using namespace std;

class Node {

public:
	Node(); //Default constructor.
	Node(Student *); //New constructor.

	Student * getData(); //get data on Student object.
	void setData(Student *); //set data for Student object.

	Node * getNext();	//get the next Node in the linked list.
	void setNext(Node * );	//set the next Node in the list.

private:
	Student * data; //pointer to current Student data.
	Node * next; //pointer within Node to the next Node.

};

#endif