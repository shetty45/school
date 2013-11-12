/**********************************************************************
* Name: Caleb Faruki
* Lab1: Huge Integer
* Course: Data Structures
* Date: June 11, 2013
* File: HugeInt Implementation
**********************************************************************/
#include "HugeInt.h"

using namespace std;

/*****************************Constructors****************************/

// Default constructor
HugeInt::HugeInt () {
    //Default all index values to 0
    for (int i = 0; i < sizeMax; i++)
	 array[i] = 0;

}

HugeInt::HugeInt (int arr[], int inputSize) {

    size = inputSize;

    //Validate that size <=40
    if (size > sizeMax)
        size = sizeMax;
    //Copy arr[] values to array[]
    for (int i = 0; i < size; i++)
        array[i] = arr[i];
    //Default to 0 for empty array indices
    for (int i = size; i < sizeMax; i++ )
        array[i] = 0;

    //Check for fencepost error
    for (int j = sizeMax - 1; j >= sizeMax - size; j--)
        array[j] = array[j - sizeMax + size];
    for (int k = 0; k < sizeMax - size; k++)
        array[k] = 0;

}

/***********************Output Stream Overload************************/

ostream &operator << (ostream &out, const HugeInt &a) {

    bool term = false;
    int count;

    //Remove excess zeroes
    for (int i = 0; i < a.sizeMax; i++) {
        if (a.array[i] != 0) {
            term = true;
            count = i;
            break;
        }
    }
    //Output remaining array
    for (int i = count; i < a.sizeMax; i++)
        out << a.array[i];

    return out;

}

istream &operator >> (istream &out, HugeInt &a) { /* nothing here */ }

/********************Comparison Operator Overloads********************/

bool HugeInt::operator == (const HugeInt &a) const {

    int count = 0;

    for (int i = 0; i < sizeMax; i++)
        if(array[i] != a.array[i])
            count++;

    if (count == 0)
        return true;
    else 
        return false;

}

bool HugeInt::operator != (const HugeInt &a) const {

    int count = 0;

    for (int i = 0; i < sizeMax; i++)
        if(array[i] != a.array[i])
            count++;

    if (count != 0)
        return true;
    else 
        return false;

}

bool HugeInt::operator > (const HugeInt &a) const {

    int count = 0;

    for (int i = 0; i < sizeMax; i++)
        if (array[i] > a.array[i])
            count++;
    else if (array[i] < a.array[i])
	    break;
	    
    if (count > 0)
        return true;
    else 
        return false;

}

bool HugeInt::operator < (const HugeInt &a) const {

    int count = 0;

    for (int i = 0; i < sizeMax; i++)
        if (array[i] < a.array[i])
            count++;
    else if (array[i] > a.array[i])
	    break;
	    
    if(count > 0)
        return true;
    else 
        return false;

}

/********************Arithmetic Operator Overloads********************/

HugeInt HugeInt::operator + (const HugeInt &a) { return add(a); }

HugeInt HugeInt::operator - (const HugeInt &a) { return subtract(a); }

HugeInt HugeInt::operator * (const HugeInt &a) { return multiply(a); }

/************************Arithmetic Algorithms************************/

HugeInt HugeInt::add (const HugeInt &a) {

    HugeInt result;
    int carry = 0;

    for (int i = sizeMax - 1; i > 0;  i--) {
        result.array[i] = (array[i] + a.array[i] + carry) % 10;
        carry = (array[i] + a.array[i] + carry) / 10;
    }
    
    return result;

}

HugeInt HugeInt::subtract (const HugeInt &a) {

    HugeInt result;
    int borrow = 0;

    for (int i = sizeMax - 1; i > 0;  i--) {
        result.array[i] = a.array[i] - array[i] - borrow;
	if (a.array[i] - array[i] < 0) {
        result.array[i] = result.array[i] + 10;
        borrow = 1;
    }
	else
	    borrow = 0;
    }
    return result;

}

HugeInt HugeInt::multiply (const HugeInt &a) { /* don't know algorithm */ }

/****************************I/O Functions****************************/

HugeInt HugeInt::input (char last) {
  
    char a;
 
    //Input characters and convert to integers
    while ((a = cin.get()) != last) {
        if (a >= '0' && a <= '9') {
            array[size] = atoi(&a);
            size++;
        }
     }

    //Check for fencepost error
    for (int i = sizeMax - 1; i >= sizeMax - size; i--)
        array[i] = array[i - sizeMax + size];
    for (int j = 0; j < sizeMax - size; j++)
        array[j] = 0;
       
}

HugeInt HugeInt::print () {

    bool term = false;
    int count;

     //Remove excess zeroes
    for (int i = 0; i < sizeMax; i++) {
        if (array[i] != 0) {
            term = true;
            count = i;
            break;
        }
    } //Don't know how to make it print if HugeInt obj = 0

    //Output remaining array indices
    for (int i = count; i < sizeMax; i++)
        cout<<array[i];

}