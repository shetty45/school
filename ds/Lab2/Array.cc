/************************************************************************
 * Name: Caleb Faruki
 * Lab2: Array Implementation
 * Course: Data Structures
 * Date: June 19, 2013
 * File: Array Implementation File
 ************************************************************************/

#include "Array.h"

/****************************Constructors*****************************/

// Default constructor
Array::Array() {

    size = DEFAULTSIZE;
    arr = new int [size]; 	// Allocate memory for array[DEFAULTSIZE].

    for (int i = 0; i < size; i++) 
        arr[i] = DEFAULTVALUE;  // Set all elements to DEFAULTVALUE.
    
}

// New constructor
Array::Array( int a ) {

    if (a < 1)
        size = DEFAULTSIZE; // Can't allocate array of <= 0 elements.
    else if (a > MAXSIZE)
        size = MAXSIZE; // Array can be no larger than 100 elements.
    else
        size = a;   // Valid argument, passed to size.

    arr = new int [size];

    for (int i = 0; i < size; i++) 
        arr[i] = DEFAULTVALUE;  // Set all elements to DEFAULTVALUE.
    
}

// Copy constructor
Array::Array( const Array & b ) { // If argument is array, copy.

    size = b.size;
    arr = new int [size]; // Set size to argument's array size.

    for (int i = 0; i < size; i++)
        arr[i] = b.arr[i]; // Copy elements.

}

// Destructor
Array::~Array () {

    for (int i = 0; i < size; i++) {
        delete arr; // Deallocate memory.
        arr = NULL; // Delete array elements.
    }

}

/*************************Operator Overloads**************************/

const Array & Array::operator=( const Array & b ) {

    delete arr; // Delete original array.
    size = b.size; // Reset size to argument's array size.
    arr = new int [size]; // Create new array of b's size.

    for (int i = 0; i < size; i++) 
        arr[i] = b.arr[i]; // Copy argument elements into new array.

    return * this; // Return value of object currently being used.

}

const bool Array::operator == ( const Array & b ) { return isEqual(b); }

const bool Array::operator != ( const Array & b ) { return isEqual(b); }

// Overload [] operator for lvalue.
int & Array::operator [] ( int a ) { return arr[a]; }

// Overload [] operator for rvalue.
int Array::operator [] ( int a ) const { return arr[a]; }

/***************************Member Functions**************************/

// Checks equality as subroutine of == & != operators
bool Array::isEqual ( const Array & b ) {

    if (size != b.size)
        return false;   // Returns != if array sizes differ.

    for (int i = 0; i < size; i++)
        if (arr[i] != b.arr[i])
            return false;   // Returns != if array contents differ.

    return true;    // Else, it returns ==.

}

void Array::input () {

    for (int i = 0; i < size; i++) {
	   cout << " Value of element(" << i+1 << "/" << size << "):";
	   cin >> arr[i];
    }

}

void Array::output () const {

    cout << "{ ";

    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';

    cout << "}" << endl;

}