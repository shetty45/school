/************************************************************************
 * Name: Caleb Faruki
 * Lab2: Template Implementation
 * Course: Data Structures
 * Date: June 19, 2013
 * File: Template Implementation File
 ************************************************************************/

#include "Template.h"

/****************************Constructors*****************************/

// Default constructor
template <typename T>
Template<T>::Template() {

    size = DEFAULTSIZE;
    ptr = new T [size]; 	// Allocate memory for array[DEFAULTSIZE].

    for (int i = 0; i < size; i++) 
        ptr[i] = DEFAULTVALUE;  // Set all elements to DEFAULTVALUE.
    
}

// New constructor
template <typename T>
Template<T>::Template( int a ) {

    if (a < 1)
        size = DEFAULTSIZE; // Can't allocate array of <= 0 elements.
    else if (a > MAXSIZE)
        size = MAXSIZE; // Template can be no larger than 100 elements.
    else
        size = a;   // Valid argument, passed to size.

    ptr = new T [size];

    for (int i = 0; i < size; i++) 
        ptr[i] = DEFAULTVALUE;  // Set all elements to DEFAULTVALUE.
    
}

// Copy constructor
template <typename T>
Template<T>::Template( const Template<T> & b ) { // If argument is array, copy.

    size = b.size;
    ptr = new T [size]; // Set size to argument's array size.

    for (int i = 0; i < size; i++)
        ptr[i] = b.ptr[i]; // Copy elements.

}

// Destructor
template <typename T>
Template<T>::~Template () {

    for (int i = 0; i < size; i++) {
        delete ptr; // Deallocate memory.
        ptr = NULL; // Delete array elements.
    }

}

/*************************Operator Overloads**************************/

template <typename T>
const Template<T> & Template<T>::operator=( const Template<T> & b ) {

    delete ptr; // Delete original array.
    size = b.size; // Reset size to argument's array size.
    ptr = new T [size]; // Create new array of b's size.

    for (int i = 0; i < size; i++) 
        ptr[i] = b.ptr[i]; // Copy argument elements into new array.

    return * this; // Return value of object currently being used.

}

template <typename T>
const bool Template<T>::operator == ( const Template<T> & b ) { return isEqual(b); }

template <typename T>
const bool Template<T>::operator != ( const Template<T> & b ) { return isEqual(b); }

// Overload [] operator for lvalue.
template <typename T>
T & Template<T>::operator [] ( int a ) { return ptr[a]; }

// Overload [] operator for rvalue.
template <typename T>
T Template<T>::operator [] ( int a ) const { return ptr[a]; }

/***************************Member Functions**************************/

// Checks equality as subroutine of == & != operators
template <typename T>
bool Template::isEqual ( const Template & b ) {

    if (size != b.size)
        return false;   // Returns != if array sizes differ.

    for (int i = 0; i < size; i++)
        if (ptr[i] != b.ptr[i])
            return false;   // Returns != if array contents differ.

    return true;    // Else, it returns ==.

}

template <typename T>
void Template::input () {

    for (int i = 0; i < size; i++) {
	   cout << " Value of element(" << i+1 << "/" << size << "):";
	   cin >> ptr[i];
    }

}

template <typename T>
void Template::output () const {

    cout << "{ ";

    for (int i = 0; i < size; i++)
        cout << ptr[i] << ' ';

    cout << "}" << endl;

}