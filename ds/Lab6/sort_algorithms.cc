/**********************************************************************
* Name: Caleb Faruki
* Lab6: Linked List III
* Course: Data Structures
* Date: August 16, 2013
* File: Sorting Algorithms
**********************************************************************/

void List::file() {
    string item;
    const int size = 20; // 20 total students in file
    ifstream file("students.txt"); // Open student.txt

    for(int i = 0; i < size; i++) { // Iterates thru List of students.
        string temp[5]; // Each loop creates a temp array.
        for(int j = 0; j < 5; j++) { // Iterates thru array elements.
            file >> item; // Extracts strings from file stream.
            temp[j] = item; // and input them into temporary stuData arrays.
        } // end for
        Student *stuPtr = new Student; // each student gets a ptr.
        input(stuPtr,temp[0],temp[1],temp[2],temp[3],temp[4]); // input temp data.
        Node *nodePtr = new Node(stuPtr); // Node created for each Student.
        append(stuPtr); // append Student to List.
    } // end for
    file.close(); // Close student.txt
    cout << endl;
} // end file()

//Sort list by Middle Initial (each Student gets a letter from the alphabet)
void List::bubbleSort() {
    bool sorted = false; // Assume List is unsorted.

    for (int pass = 1; (pass <= numNodes) && !sorted; ++pass) { //Never exceed numNodes.
        for(Node *curr=head; curr!=tail; curr=curr->getNext()) { //Traverse list.

            if(curr->getData()->getMid() > curr->getNext()->getData()->getMid()) {
                swap(curr, curr->getNext()); // compare curr and next Nodes, swap.
                sorted = false; //must check at least 1 more time to validate sorting.
            } // end if
        } // end for
    } // end for
    sorted = true;
} // end bubbleSort()

//Sort list by Middle Initial opposite order.
void List::selectSort() {
    bool sorted = false; // Assume List is unsorted.
    Node *base = tail; // Start from end of list.

    for(int pass=1; (pass<=numNodes)&&!sorted; ++pass) { //Never exceed numNodes.
        for(Node *curr=tail; curr!=head; curr=curr->getPrev()){ //Traverse list reverse.
            
            if(curr->getData()->getMid() > base->getData()->getMid()) {
                swap(curr, base); //check base against each Node in list, swap if necessary.
                sorted = false; //must make 1 more pass at least.
            } // end if
        } // end for
        base = base->getPrev(); //after traversal, move the base by 1.
    } // end for
    sorted = true;
} // end selectSort()

void List::swap(Node *curr, Node *next) {
    Student *temp = curr->getData(); // Save curr Node data elsewhere.
    //swap 
    curr->setData(next->getData()); // Currs data equal to nexts data.
    next->setData(temp); // Put original curr data into next pointer.
} // end swap()