List::List(const List &list) { // Copy constructor
    head = NULL; // Head pointer set to NULL initially
    tail = NULL; // Tail pointer set to NULL initially

    empty = true;
    numNodes = 0;

    Node *curr = list.getHead(); // curr points to list head.
	cout << "Copying from head-to-tail...\n" << endl;

    while(curr) {
        string f = ( curr->getData()->getFirst()  );
        string m = ( curr->getData()->getMid()    );
        string l = ( curr->getData()->getLast()   );
        string s = ( curr->getData()->getSocial() );
        string a = ( curr->getData()->getAge()    );

        Node *nodePtr = NULL; // a node that's pointing 
                              // using it to point to creation of
                              // a new node
        Student *stuPtr = new Student; // creates a stud pointer on
                                       // heap of Student class in
                                       // order to store stud info 
        input(stuPtr,f,m,l,s,a); // input Student::data into stuPtr.      
        append(stuPtr); // append the node with stuPtr to head or tail
          				// of list.

        curr = curr->getNext();
    }  // end while*/
    cout << "Done copying!\n" << endl;
} // end copy constructor