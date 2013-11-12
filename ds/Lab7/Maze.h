/**********************************************************************
* Name: Caleb Faruki
* Lab7: Recursive Maze
* Course: Data Structures
* Date: August 16, 2013
* File: Maze Class
 *********************************************************************/
#ifndef MAZE_H
#define MAZE_H

#include <iostream>

using namespace std;

static int count; //global variable that counts # of steps.

class Maze {

public:
    Maze(); // constructor

    void startPoint(int, int); // start point for user, x,y coordinates
    bool exitR(int, int); // recursive to backtracks to prev position
                          // when non-'O' position is encountered.
    void print(); // print function.

private:
    static const int rows = 4; // total rows in Maze.
    static const int cols = 5; // total columns in Maze.
    char array[rows] [cols];  // 2D char array represents the Maze.

    bool validMove(int,int);

    bool start; //start point is valid: yes or no?
    bool path; //path to exit exists: yes or no?
};
#endif