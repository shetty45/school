#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <iostream>
#include <time.h>

class Array {

public:
	Array(); //default
	Array(int); //new
	~Array(); //destroy

	void quickSort(const Array &, int, int);
	int partition(const Array &, int, int, int&);
	void swap(int&, int&);	

	void best();
	void worst();
	void avg();
	void printArray();

private:
	bool isSorted();

	static const int DEFSIZE = 10;
	static const int MAXSIZE = 100;
	static const int DEFVAL = 0;
	int size;
	int * arr;
};

#endif