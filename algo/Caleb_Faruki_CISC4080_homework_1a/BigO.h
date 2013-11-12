#ifndef BIGO_H
#define BIGO_H

#include <cmath>
#include <iostream>

using namespace std;

class BigO {

public:
	BigO(); //default constructor

	double gnOne(int); // log(n)
	int gnTwo(int);  // n
	double gnThree(int);  // sqrt(n)
	double gnFour(int); // n*log(n)
	int gnFive(int); // n^2
	int gnSix(int); // n^3
	int gnSeven(int); // 2^n
	int gnEight(int); // n!
	double gnNine(int); // n^(3/2)*log(n)

private:
	int n; // input size
};

#endif