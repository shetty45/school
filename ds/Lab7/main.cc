/**********************************************************************
* Name: Caleb Faruki
* Lab7: Recursive Maze
* Course: Data Structures
* Date: August 16, 2013
* File: Main Function
 *********************************************************************/
#include "Maze.h"

int main() {

    Maze maze; // instantiate object of class Maze.

    int x, y; // args for startPoint() and exitR()

    cout << endl;
    cout << "Initial Maze display:" << endl;
    maze.print(); // print default maze.

    cout << "Enter starting coords (x,y) from (0,0) to (3,4): " << endl;
    cout << endl;
    cout << "Coord x = ";
    cin >> x;
    cout << "Coord y = ";
    cin >> y;
    cout << "Starting coords : (x=" << x << ",y=" << y << ")\n" << endl;

    cout << "'S' = starting point, 'E' = exit" << endl;

    maze.startPoint(x,y); // validates and inserts 'S' value into element.
    maze.print(); // reprint maze with newly inserted 'S' element.

    cout << "Final Maze display:\n" << endl;
    if(maze.exitR(x,y)) { // takes original x,y to initiate recursion.
        maze.print(); // reprint maze, showing all marked elements visited.
        cout << "\nYou escaped!\n" << endl;
    } else {
        maze.print();
        cout << "\nThere was no exit from the starting point.\n" << endl;
    }

	return 0;
}