/**********************************************************************
* Name: Caleb Faruki
* Lab5: Linked List II
* Course: Data Structures
* Date: July 17, 2013
* File: Node Class
**********************************************************************/

#ifndef NODE_H
#define NODE_H

#include "Student.h"

using namespace std;

class Node {

public:
    Node();
    Node(Student *);// new constructor that takes Student arg for data.

    Student *getData() {return data;} // gets Node data.
    void setData(Student*); // set Node data. 

    Node *getNext() {return next;} // gets whatever this Node pts to next.
    void setNext(Node*); // sets where this Node pts to next.

    Node *getPrev() {return prev;}// gets whatever this Node pts to prev.
    void setPrev(Node*);// sets where this Node pts to prev.

    void printNode(Node *); //print a particular Node.

private:
    Student *data;// student data member
    Node *next;// pointer-based node
    Node *prev;// pointer-prev node
};

#endif