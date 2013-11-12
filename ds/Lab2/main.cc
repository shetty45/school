/************************************************************************
 * Name: Caleb Faruki
 * Lab2: Array Implementation
 * Course: Data Structures
 * Date: June 19, 2013
 * File: Array Main Function
 ************************************************************************/

#include "Array.h"

int main () {

    int arrSize;
    cout << "Specify size of arrOne & arrTwo: ";
    cin >> arrSize;
    cout << endl;

    Array arrOne(arrSize); // New constructor called for arrOne
    Array arrTwo(arrOne); // Copy constructor called for arrTwo
    
    // Print contents of both arrays (all elements == DEFAULTVALUE).
    cout << "Printing contents of both arrays: " << endl 
         << "arrOne[size==" << arrSize << "]: " << arrOne 
         << "arrTwo[size==" << arrSize << "]: " << arrTwo;

    // Show that copy constructor works.
    if (arrOne == arrTwo)
        cout << "arrOne == arrTwo.\n" << endl;
    
    // Set value of 1st element to arrSize.
    arrOne[0] = arrSize;
    cout << "Now, arrOne[0] == " << arrOne[0] << endl << endl;
    
    // Manually set all values for arrTwo.
    cout << "Now enter elements for arrTwo." << endl;
    cin >> arrTwo;
    cout << endl;
    
    // Print contents of both arrays.
    cout << "Printing contents of both arrays:\n" << "arrOne: " 
         << arrOne << "arrTwo: " << arrTwo;
    
    // Check equality of arrOne & arrTwo.
    if (arrOne == arrTwo)
        cout << "arrOne == arrTwo.\n" << endl;
    else 
        cout << "arrOne != arrTwo.\n" << endl;

	return 0;

}