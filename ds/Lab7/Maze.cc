/**********************************************************************
* Name: Caleb Faruki
* Lab7: Recursive Maze
* Course: Data Structures
* Date: August 16, 2013
* File: Maze Implementation
 *********************************************************************/
#include "Maze.h"

Maze:: Maze(){
// 'O' open position, 'X' blocked position, 'E' exit
// Pre-fixed 2D matrix.
    array[0][0] = 'O';
    array[0][1] = 'O';
    array[0][4] = 'O';
    array[1][0] = 'O';
    array[1][2] = 'O';
    array[1][3] = 'O';
    array[2][0] = 'O';
    array[2][1] = 'O';
    array[2][2] = 'O';
    array[2][3] = 'O';
    array[3][2] = 'O';
    array[0][2] = 'X';
    array[1][1] = 'X';
    array[1][4] = 'X';
    array[2][4] = 'X';
    array[3][0] = 'X';
    array[3][1] = 'X';
    array[3][3] = 'X';
    array[3][4] = 'X';
    array[0][3] = 'E';
} //maze constructor, which initializes the maze

void Maze::startPoint(int x, int y) {
    if (validMove(x,y))
        array[rows-(y+1)][x] = 'S'; // 'S' indicates startPoint.
    else
        cerr << "Bad start point" << endl;
} // end startPoint()

//false = no exit, true = exit
bool Maze::exitR(int x, int y){
    if (!validMove(x,y))
        return path = false;
    count++; //increment # of moves.

    if( array[y][x] == 'E' ) { // base case.
        count++;
        cout << "You marked " << count << " cells en route to 'E'.\n" << endl;
        return path = true;
    } // recursion.
    else if (array[y][x] != 'E') { // look to adjacent elements for 'O' value.
        //don't overwrite 'E'or'S'
        if (array[rows-(y+1)][x] != 'E' && array[rows-(y+1)][x] != 'S')
            array[rows-(y+1)][x] = 'M'; //mark visited element.

        count++;
        //1st, try left.
        if(array[rows-(y+1)][x-1]=='O'||array[rows-(y+1)][x-1]=='E') {
            exitR(x-1,y);
            count++;
        } //2nd, try right.
        if(array[rows-(y+1)][x+1]=='O'||array[rows-(y+1)][x-1]=='E') {
            exitR(x+1,y);
            count++;
        } //3rd, try down.
        if(array[rows-y][x]=='O'||array[rows-(y+1)][x-1]=='E') {
            exitR(x,y-1); 
            count++;
        } //last, try up.
        if(array[rows-(y+2)][x]=='O'||array[rows-(y+1)][x-1]=='E') {
            exitR(x,y+1); 
            count++;
        } //out of options
    } // end if/elseif
    return path; //if points are not valid then return false
} // end exitR()

void Maze::print() {
    int rCount = rows-1;

    for (int i = 0; i < rows; i++){
        cout << "   +---+---+---+---+---+" << endl;

        cout << " " << rCount; // print y axis
        for (int j = 0; j < cols; j++){
            cout << " | " << array[i][j];
            if ((j+1) % 5 == 0)
                cout << " | " << endl;
        } // end for
        rCount--;
    } // end for
    cout << "   ---------------------\n" << "    ";
    for(int i=0; i<cols; i++) 
        cout << " " << i << "  "; // print x axis
    cout << endl << endl;
} // end print()

bool Maze::validMove(int x, int y) {
    if (x >= 0 || y >= 0 || x < cols || y < rows || array[y][x] == 'O'
        || array[y][x] == 'S' || array[y][x] == 'E')
        return true;
    else 
        return false;
} // end validMove()