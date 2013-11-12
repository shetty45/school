/**********************************************************************
 * Name: Caleb Faruki
 * Lab3: Template Array
 * Course: Data Structures
 * Date: July 3, 2013
 * File: Template Main Function File
 *********************************************************************/

#include "Template.h"

int main () {

    int arrSize;
    cout << "Specify size of arrays intOne & intTwo: ";
    cin >> arrSize;
    cout << endl;

/***************************Integer Template**************************/

    cout << "~~~TEMPLATE<INT>~~~\n" << endl;

    Template<int> intOne(arrSize); // New constructor called for intOne
    Template<int> intTwo(intOne); // Copy constructor called for intTwo
    
    // Print contents of both arrays (all elements == DEFAULTVALUE).
    cout << "Printing contents of both arrays: " << endl 
         << "intOne[size==" << arrSize << "]: " << intOne 
         << "intTwo[size==" << arrSize << "]: " << intTwo;

    // Show that copy constructor works.
    if (intOne == intTwo)
        cout << "intOne == intTwo.\n" << endl;
    
    // Set value of 1st element to arrSize.
    intOne[0] = arrSize;
    cout << "Now, intOne[0] == " << intOne[0] << endl << endl;
    
    // Manually set all values for arrTwo.
    cout << "Now enter elements for intTwo." << endl;
    cin >> intTwo;
    cout << endl;
    
    // Print contents of both arrays.
    cout << "Printing contents of both arrays:\n" << "intOne: " 
         << intOne << "intTwo: " << intTwo;
    
    // Check equality of arrOne & arrTwo.
    if (intOne == intTwo)
        cout << "intOne == intTwo.\n" << endl;
    else 
        cout << "intOne != intTwo.\n" << endl;

/*************************Character Template**************************/

    cout << "~~~TEMPLATE<CHAR>~~~\n" << endl;

    Template<char> charOne; // Default constructor called for charOne
    // All values default set to ' '.

    cout << "Now specify size of array charTwo: ";
    cin >> arrSize;
    cout << endl;

    Template<char> charTwo(arrSize); // New constructor call

    // Print contents of both arrays.
    cout << "Printing contents of both arrays:\n" << "charOne: " 
         << charOne << "charTwo: " << charTwo;
    
    // Check equality of charOne & charTwo.
    if (charOne == charTwo)
        cout << "charOne == charTwo.\n" << endl;
    else 
        cout << "charOne != charTwo.\n" << endl;

    // Set value of 1st element to '%'.
    charOne[0] = '%';
    cout << "Now, charOne[0] == " << charOne[0] << endl << endl;
    
    // Manually set all values for charTwo.
    cout << "Now enter elements for charTwo." << endl;
    cin >> charTwo;
    cout << endl;

    cout << "Printing contents of both arrays:\n" << "charOne: " 
         << charOne << "charTwo: " << charTwo;

/**************************Double Template***************************/

    cout << "\n~~~TEMPLATE<DOUBLE>~~~\n" << endl;

    Template<double> dblOne;

    cout << "Now specify size of array dblTwo: ";
    cin >> arrSize;
    cout << endl;

    Template<double> dblTwo(arrSize);

    cout << "Printing contents of both arrays:\n" << "dblOne: " 
         << dblOne << "dblTwo: " << dblTwo;

    if (dblOne == dblTwo)
        cout << "dblOne == dblTwo.\n" << endl;
    else 
        cout << "dblOne != dblTwo.\n" << endl;

    // Set value of 1st element to '%'.
    dblOne[0] = 6.54321;
    cout << "Now, dblOne[0] == " << dblOne[0] << endl << endl;
    
    cout << "Now enter elements for dblTwo." << endl;
    cin >> dblTwo;
    cout << endl;

    cout << "Printing contents of both arrays:\n" << "dblOne: " 
         << dblOne << "dblTwo: " << dblTwo;

    return 0;

}
