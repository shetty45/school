/**********************************************************************
* Name: Caleb Faruki
* Lab1: Huge Integer
* Course: Data Structures
* Date: June 11, 2013
* File: HugeInt Header
**********************************************************************/
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class HugeInt {   

    friend ostream& operator << (ostream &, const HugeInt &);
    friend istream& operator >> (istream &, HugeInt &); //Not implemented

public:

    HugeInt();
    HugeInt(int[], int);

    bool operator == (const HugeInt &) const;
    bool operator != (const HugeInt &) const;
    bool operator > (const HugeInt &) const;
    bool operator < (const HugeInt &) const;

    HugeInt operator + (const HugeInt &);
    HugeInt operator - (const HugeInt &);
    HugeInt operator * (const HugeInt &);

    HugeInt print();

private:

    HugeInt add(const HugeInt &);
    HugeInt subtract(const HugeInt &);
    HugeInt multiply(const HugeInt &); //Not implemented

    HugeInt input(char);

    static const int sizeMax = 40;
    int array[sizeMax + 1];
    int size;

};

#endif