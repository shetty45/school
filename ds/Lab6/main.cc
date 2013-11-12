/**********************************************************************
* Name: Caleb Faruki
* Lab6: Linked List III
* Course: Data Structures
* Date: August 16, 2013
* File: Main Function
**********************************************************************/
#include "List.h"

using namespace std;

int main() {
    List aList;

    aList.file(); // read in students.txt.
    cout << "***********aList****************" << endl;
    aList.display();

    List bList(aList); // copy contents into new List.
    cout << "******bList after copying*******" << endl;
    bList.display();

    bList.bubbleSort(); // bubbleSort into ascending order.
    cout << "*****bList after bubbleSort*****" << endl;
    bList.display();

    bList.selectSort(); // selectSort into descending order.
    cout << "*****bList after selectSort*****" << endl;
    bList.display();

    return 0;

}
/*
1. read in file.
2. display aList as is.
3. copy list into new list.
4. bubbleSort bList (i.e. ascending order)
5. display bList as is.
6. selectSort bList (i.e. descending order)
7. display bList as is.
*/