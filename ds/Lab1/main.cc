/**********************************************************************
* Name: Caleb Faruki
* Lab1: Huge Integer
* Course: Data Structures
* Date: June 11, 2013
* File: HugeInt Main Function
**********************************************************************/
#include "HugeInt.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {

    cout << "|***************|ADDITION|****************|" << endl;

    int addArray1[5] = {3,8,9,5,4};
    int addArray2[3] = {2,3,6};

    HugeInt addOp1(addArray1, 5);
    HugeInt addOp2(addArray2, 3);
    HugeInt addResult1;
    
    cout << "\nFirst Addition Operation:\n" << endl;

    if (addOp1 == addOp2)
        cout << addOp1 << " == " << addOp2 << endl;
    else if (addOp1 != addOp2) {
        cout << addOp1 << " != " << addOp2 << endl;
        if (addOp1 > addOp2)
            cout << addOp1 << " > " << addOp2 << endl;
        else if (addOp1 < addOp2)
            cout << addOp1 << " < " << addOp2 << endl;
    }

    addResult1 = addOp1 + addOp2;
    cout << addOp1 << " + " << addOp2 << " = " << addResult1 << endl;

    int addArray3[2] = {4,2};
    int addArray4[4] = {8,9,5,5};

    HugeInt addOp3(addArray3, 2);
    HugeInt addOp4(addArray4, 4);
    HugeInt addResult2;

    cout << "\nSecond Addition Operation:\n" << endl;

    if (addOp3 == addOp4)
        cout << addOp3 << " == " << addOp4 << endl;
    else if (addOp3 != addOp4) {
        cout << addOp3 << " != " << addOp4 << endl;
        if (addOp3 > addOp4)
            cout << addOp3 << " > " << addOp4 << endl;
        else if (addOp3 < addOp4)
            cout << addOp3 << " < " << addOp4 << endl;
    }

    addResult2 = addOp3 + addOp4;
    cout << addOp3 << " + " << addOp4 << " = " << addResult2 << endl;

    int addArray5[4] = {0,3,6,6};
    int addArray6[3] = {3,6,6};

    HugeInt addOp5(addArray5, 4);
    HugeInt addOp6(addArray6, 3);
    HugeInt addResult3;

    cout << "\nThird Addition Operation:\n" << endl;

    if (addOp5 == addOp6)
        cout << addOp5 << " == " << addOp6 << endl;
    else if (addOp5 != addOp6) {
        cout << addOp5 << " != " << addOp6 << endl;
        if (addOp5 > addOp6)
            cout << addOp5 << " > " << addOp6 << endl;
        else if (addOp5 < addOp6)
            cout << addOp5 << " < " << addOp6 << endl;
    }

    addResult3 = addOp5 + addOp6;
    cout << addOp5 << " + " << addOp6 << " = " << addResult3 << endl << endl;

    cout << "|**************|SUBTRACTION|**************|" << endl;

    int subArray1[6] = {4,5,6,7,8,9};
    int subArray2[7] = {0,4,5,6,7,8,9};

    HugeInt subOp1(subArray1, 6);
    HugeInt subOp2(subArray2, 7);
    HugeInt subResult1;

    cout << "\nFirst Subtraction Operation:\n" << endl;

    if (subOp1 == subOp2)
        cout << subOp1 << " == " << subOp2 << endl;
    else if (subOp1 != subOp2) {
        cout << subOp1 << " != " << subOp2 << endl;
        if (subOp1 > subOp2)
            cout << subOp1 << " > " << subOp2 << endl;
        else if (subOp1 < subOp2)
            cout << subOp1 << " < " << subOp2 << endl;
    }

    subResult1 = subOp2 - subOp1;
    cout << subOp1 << " - " << subOp2 << " = " << subResult1 << endl;

    int subArray3[3] = {8,2,0};
    int subArray4[2] = {8,2};

    HugeInt subOp3(subArray3, 3);
    HugeInt subOp4(subArray4, 2);
    HugeInt subResult2;

    cout << "\nSecond Subtraction Operation:\n" << endl;

    if (subOp3 == subOp4)
        cout << subOp3 << " == " << subOp4 << endl;
    else if (subOp3 != subOp4) {
        cout << subOp3 << " != " << subOp4 << endl;
        if (subOp3 > subOp4)
            cout << subOp3 << " > " << subOp4 << endl;
        else if (subOp3 < subOp4)
            cout << subOp3 << " < " << subOp4 << endl;
    }

    subResult2 = subOp4 - subOp3;
    cout << subOp4 << " - " << subOp3 << " = " << subResult2 << endl;

    int subArray5[4] = {4,4,4,4};
    int subArray6[4] = {3,4,4,4};

    HugeInt subOp5(subArray5, 4);
    HugeInt subOp6(subArray6, 4);
    HugeInt subResult3;

    cout << "\nThird Subtraction Operation:\n" << endl;

    if (subOp5 == subOp6)
        cout << subOp5 << " == " << subOp6 << endl;
    else if (subOp5 != subOp6) {
        cout << subOp5 << " != " << subOp6 << endl;
        if (subOp5 > subOp6)
            cout << subOp5 << " > " << subOp6 << endl;
        else if (subOp5 < subOp6)
            cout << subOp5 << " < " << subOp6 << endl;
    }

    subResult3 = subOp6 - subOp5;
    cout << subOp5 << " - " << subOp6 << " = " << subResult3 << endl << endl;

}