/**********************************************************************
* Name: Caleb Faruki
* Lab5: Linked List II
* Course: Data Structures
* Date: July 17, 2013
* File: Node Class Implementation
**********************************************************************/
#include "Node.h"

using namespace std;

Node::Node() {  // default constuctor
	data = NULL;
    next = NULL;
    prev = NULL;
} // end default constructor

Node::Node(Student * student) { // Student arg becomes Node data.
    setData(student);
    next = NULL;
    prev = NULL;
} // end new constructor

void Node::setData(Student * student) {
    data = student;
} // end setData()

void Node::setNext(Node * nextNode) {
    next = nextNode;
} // end setNext()

void Node::setPrev(Node * prevNode) {
    prev = prevNode;
} // end setPrev()

void Node::printNode(Node * node) {
	Node *curr = node;
    cout << "{"
         << curr->getData()->getFirst()  << ", "
         << curr->getData()->getMid()    << ", "
         << curr->getData()->getLast()   << ", "
         << curr->getData()->getSocial() << ", "
         << curr->getData()->getAge()    << "}" << endl;
} // end printNode()