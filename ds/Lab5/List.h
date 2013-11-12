/**********************************************************************
* Name: Caleb Faruki
* Lab5: Linked List II
* Course: Data Structures
* Date: July 17, 2013
* File: List Class
**********************************************************************/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Student.h"
#include "Node.h"
using namespace std;

class List {

public:
    List(); // Default constructor
    List(const List&); // Copy constructor (2-in-1, see lab sheet)
    ~List(); // Destructor

    bool isEmpty(); // List is empty: TRUE or FALSE?
    int getNumNodes() {return numNodes;} // How many Nodes in List
    
    void append(Student *); // Append new Node to head or tail of List
    void insert(Student *); // Inserts new Node in the
                            // Appropriate location in List
    void deleteNode(string); //Search for and delete specific Node
    void displayAscending();// Display List HEAD to TAIL
    void displayDescending(); // Display List TAIL to HEAD

    // input Student::data into Student pointer.
    void input(Student*, string, string, string, string, string);

    Node *getHead() const {return head;} // ptr to head. 
    Node *getTail() const {return tail;} //ptr to tail.

    bool copyReverse(); //ask whether normal or reverse copy.
                       //intended for main before copy constructor.
private:
    void printer(Node *); //recursive function w/in displayDescending()
    Node *head;
    Node *tail;

    bool empty;
    bool forward; // forward = head-to-tail i.e. true
    int numNodes; // number of nodes in the list 
};

#endif