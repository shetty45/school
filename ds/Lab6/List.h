/**********************************************************************
* Name: Caleb Faruki
* Lab5: Linked List II
* Course: Data Structures
* Date: July 17, 2013
* File: List Class
**********************************************************************/
#ifndef LIST_H
#define LIST_H

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
    void display();// Display List HEAD to TAIL

    // input Student::data into Student pointer.
    void input(Student*, string, string, string, string, string);

    Node *getHead() const {return head;} // ptr to head. 
    Node *getTail() const {return tail;} //ptr to tail.

    void file(); // Converts text file to List of Nodes.

    void bubbleSort(); // Sorts nodes in ascending order.
    void selectSort(); // Sorts nodes in descending order.

private:
    void swap(Node *, Node *); // subroutine of sort algorithms.
    Node *head;
    Node *tail;

    bool empty;
    bool forward;
    int numNodes; // number of nodes in the list 
};

#endif

/*set curr to head //curr traverses the list
set index to head //index holds the largest aged node
set base to head. //points to next node after every pass.
curr traverses list (until curr == head)
    compare curr->age to temp->age
    if curr > index, swap
    swap temp and */