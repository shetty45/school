/**********************************************************************
* Name: Caleb Faruki
* Lab5: Linked List II
* Course: Data Structures
* Date: July 17, 2013
* File: Main Function
**********************************************************************/

#include <iostream>
#include "List.h"

using namespace std;

int main() {
    Student hershel ("Hershel","A","Monsivals","111-22-3333","11");
    Student lucila  ("Lucila", "B","Stearn",   "222-33-4444","12");
    Student robbie  ("Robbie", "C","McCollum", "333-44-5555","13");
    Student dolores ("Dolores","D","Cooks",    "444-55-6666","14");
    Student crystal ("Crystal","E","Ottman",   "555-66-7777","15");

    Student *pHershel = &hershel;
    Student *pLucila = &lucila;
    Student *pRobbie = &robbie;
    Student *pDolores = &dolores;
    Student *pCrystal = &crystal;

    List aList;
    aList.append(pHershel);
    aList.append(pLucila);
    aList.append(pRobbie);
    aList.append(pDolores);
    aList.append(pCrystal);
    aList.displayAscending();

    List bList(aList);
    bList.displayAscending();

    Student josh ("Josh","F","Ginsberg","666-77-8888","16");
    Student *pJosh = &josh;
    Node six(pJosh);

    bList.insert(pJosh);
    bList.displayAscending();

    bList.deleteNode("Dolores");
    bList.displayDescending();

    return 0;

}