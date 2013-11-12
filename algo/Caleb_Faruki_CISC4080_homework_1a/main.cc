#include "BigO.h"

int main() {

	cout << "For inputs size 1 thru 12:\n" << endl;

	BigO Homework;

	for (int i=0; i<12; i++) {
		cout << "For n = " << i+1 << "..." << endl
			<< "\t   logn = " << Homework.gnOne(i+1) << endl
			<< "\t      n = " << Homework.gnTwo(i+1) << endl
			<< "\tsqrt(n) = " << Homework.gnThree(i+1) << endl
			<< "\t n*logn = " << Homework.gnFour(i+1) << endl
			<< "\t    n^2 = " << Homework.gnFive(i+1) << endl
			<< "\t    n^3 = " << Homework.gnSix(i+1) << endl
			<< "\t    2^n = " << Homework.gnSeven(i+1) << endl
			<< "\t     n! = " << Homework.gnEight(i+1) << endl
			<< "   n^(3/2)*logn = " << Homework.gnNine(i+1) << endl
			<< endl;
	}

	return 0;

}