/**********************************************************************
* Name: Caleb Faruki
* Lab4: Basic Linked List
* Course: Data Structures
* Date: July 10, 2013
* File: Driver File
**********************************************************************/

#include "Node.h"
#include "Student.h"

using namespace std;

void append (Node **, Node *); //append Node to end of list.
void display(Node *); //print linked list.
void input(Student *); //enter new Student object.
void deletes(Node **, string); //delete specific Node.

string first;
string mid;
string last;
string ssn;
string age;

int main() {

	string flag; //flag checks for delimiter.
	string name;
	string stuDelete; //name to be deleted.

	Student * stuPtr = NULL;
	Node * head = NULL;
	Node * newPtr = NULL;

	do {
		stuPtr = new Student;
		input(stuPtr);
		flag = stuPtr->getFirst(); //flag = first name.

		if(stuPtr->getFirst() == "-") { //"-" is delimiter.
			delete stuPtr; //no new Student, no need for pointer.
			stuPtr = NULL;
		}
		else {
			newPtr = new Node(stuPtr);
			append(& head, newPtr);
		}
	} while (first != "-"); //prompts for more entries until
						   //delimiter is detected.
	display(head);

	if(head)
		cout << "Enter a Student to be deleted" << endl;
	while(head) {
		cout << "Last name: ";
		cin >> stuDelete;
		deletes(& head, stuDelete);

		string reqDelete; //asks if you want to keep deleting.
		cout << "Student has been deleted. Delete another? (Y/N): ";
		cin >> reqDelete;

		if((head) && (reqDelete == "Y")) {
			display(head); //iterates thru linked list.
			cout << "\nEnter another name to be deleted: \n" << endl;
		}
		else if(reqDelete != "Y") {
			cout << "Deletion complete.\n" << endl;
			break;
		}
	}

	if(head) {
		cout << "Here are the remaining Students in the list:" << endl;
		display(head);
	}
	else
	cout << "The list is now empty.\n"
		 << "=============================" << endl;

		 return 0;
}

void append(Node ** head, Node * newPtr) {
	
	Node * curr = * head;

	if (curr) {
		while (curr->getNext() != NULL)
			curr = curr->getNext();
		curr->setNext(newPtr);
	}
	else
		* head = newPtr;
}

void display(Node * newPtr) {

    Node * curr = newPtr; 

    while(curr) {
	// getData is used to point to the stud info in a node
	cout << "{" 
	     << curr->getData()->getFirst() << ", "
	     << curr->getData()->getMiddle() << ", "
	     << curr->getData()->getLast()<< ", "
	     << curr->getData()->getSocial()<< ", "
	     << curr->getData()->getAge()
	     << "}" << endl;	

	curr = curr->getNext(); // move to the next obj, traverse stud data
    }

    cout << "-----------------------------------------" << endl;
}

/*	if(!newPtr) //No students.
		cout << "No Students in list." << endl;
	else if (newPtr -> getNext() == NULL) { //Only 1 Student.
		cout << "{"
	    	 << newPtr -> getData() -> getFirst() << ", "
	    	 << newPtr -> getData() -> getMiddle() << ", "
	    	 << newPtr -> getData() -> getLast() << ", "
	    	 << newPtr -> getData() -> getSocial() << ", "
	    	 << newPtr -> getData() -> getAge()
	    	 << "}" << endl;	
	}
	else {
		cout << "{"
	    	 << newPtr -> getData() -> getFirst() << ", "
	    	 << newPtr -> getData() -> getMiddle() << ", "
	    	 << newPtr -> getData() -> getLast() << ", "
	    	 << newPtr -> getData() -> getSocial() << ", "
	    	 << newPtr -> getData() -> getAge()
	    	 << "}" << endl;	

	    	 newPtr = newPtr -> getNext();

	    	 cout << "..." << endl;
	}
}*/

void input(Student * stuPtr) {

	cout << "\nEnter Student information (Enter '-' to exit)\n"
		 << "First Name: ";
	cin >> first;

	if(first == "-") {
		stuPtr->setName(first, mid, last);
		cout << "Student entry finished.\n" << endl;
	}
	else {
		cout << "Middle Name: ";
		cin >> mid;

		cout << "Last Name: ";
		cin >> last;

		stuPtr->setName(first, mid, last);

		cout << "Social: ";
		cin >> ssn;
		stuPtr->setSocial(ssn);

		cout << "Age: ";
		cin >> age;
		stuPtr->setAge(age);
	}
	cout << "==============================" << endl;
}

void deletes(Node ** head, string stuDelete) {

	Node * curr = * head;
	Node * prev = NULL;

	if(!curr)
		cout << "No Students in list" << endl;
	else {
		while(curr) {
			if(curr->getData()->getLast() == stuDelete) {
				cout << "\n==============================\n"
					 << "The following student is pointed to:\n"
					 << "{" 
	    			 << curr->getData()->getFirst() << ", "
	    			 << curr->getData()->getMiddle() << ", "
	    			 << curr->getData()->getLast()<< ", "
	    			 << curr->getData()->getSocial()<< ", "
	    			 << curr->getData()->getAge()
	    			 << "}" << endl;	
			break; //break if name to be deleted is found.
			}
			else {
				prev = curr;
				curr = curr->getNext(); //traverse list.
			}
		}
		if (!prev) { //if at head of list.
			* head = curr->getNext(); //point to next Node.
			curr -> setNext(NULL);
			delete curr; //delete this Node.
			curr = NULL;
		}
		else {
			prev -> setNext(curr->getNext());
			curr -> setNext(NULL);
			delete curr;
			curr = NULL;
		}
	}
}