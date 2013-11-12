/************************************************************************
 * Name: Caleb Faruki
 * Lab2: Array Implementation
 * Course: Data Structures
 * Date: June 19, 2013
 * File: Array Header File
 ************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array {

    friend istream & operator>>( istream & in, Array & a ) {
	   a.input();
	   return in;
    }

    friend ostream & operator<<( ostream & out, const Array & a ) {
	   a.output();
	   return out;
    }

public:

    Array ();   // Default constructor
    Array ( int );   // New constructor
    Array ( const Array & );   // Copy constructor
    ~Array ();   // Destructor.

    // Operator overload prototypes.
    const Array & operator=( const Array & );
    const bool operator==( const Array & );
    const bool operator!=( const Array & );

    int & operator[]( int );	// Left hand operator.
    int operator[]( int ) const;	// Right hand operator.

private:

    // Member function prototypes
    bool isEqual ( const Array & );
    void input();
    void output() const;

    static const int DEFAULTSIZE = 10; // Set default array size.
    static const int MAXSIZE = 100; // Set maximum array size.
    static const int DEFAULTVALUE = 0; // Set value of array elements.
    int size;
    int * arr;

};

#endif