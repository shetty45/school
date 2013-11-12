/**********************************************************************
* Name: Caleb Faruki
* Lab4: Basic Linked List
* Course: Data Structures
* Date: July 10, 2013
* File: Node Class Implementation
**********************************************************************/

#include "Node.h"

using namespace std;

Node::Node() {
	next = NULL; //new Nodes go to the end of the list.
}

Node::Node(Student * tempData) {
	data = tempData;
	next = NULL;
}

Student * Node::getData() { return data; }

void Node::setData(Student * tempData) {
	data = tempData;
}

Node * Node::getNext() { return next; }

void Node::setNext(Node * nextNode) {
	next = nextNode;
}