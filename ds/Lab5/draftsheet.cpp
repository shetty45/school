

List::List(const List &aList): numNodes(aList.numNodes) { // Copy constructor
    head = NULL; // Head pointer set to NULL initially
    tail = NULL; // Tail pointer set to NULL initially

    empty = true;
    forward = true; // Copies head-to-tail by default.
    numNodes = 0;

    string flag; // Stores prompt value.
	cout << "Copy from head to tail? (y/n): ";
	cin >> flag; // prompt for user.
    if(flag == "n")
        forward = false;

	Node *curr = NULL; //initialize curr in function scope.

    curr = list.getHead();
    cout << "Copying from head-to-tail...\n" << endl;

    while(curr) {
        string f = (curr->getData()->getFirst());
        string m = ( curr->getData()->getMid());
        string l = ( curr->getData()->getLast() );
        string s = ( curr->getData()->getSocial());
        string a = ( curr->getData()->getAge()  );

        Student *stuPtr = new Student; // creates a stud pointer on
                                       // heap of Student class in
                                       // order to store stud info 
        input(stuPtr,f,m,l,s,a); // input Student::data into stuPtr.      
        append(stuPtr); // append the node with stuPtr to head or tail
                      // of list.
        curr = curr->getNext();
    }
    cout << "Done copying!\n" << endl;
} // end copy constructor()