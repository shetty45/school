#include "BigO.h"

BigO::BigO() {
	int n = 0;
}

double BigO::gnOne(int n) { // logn
	return log(n); 
} // end gnOne()

int BigO::gnTwo(int n) { // n
	return n; 
} // end gnTwo()

double BigO::gnThree(int n) { // sqrt(n)
	return sqrt(n); 
} // end gnThree()

double BigO::gnFour(int n) {  // n*logn
	return n*log(n); 
} // end gnFour()

int BigO::gnFive(int n) { // n^2
	return pow(n,2); 
} // end gnFive()

int BigO::gnSix(int n) { // n^3
	return pow(n,3); 
} // end gnSix()

int BigO::gnSeven(int n) { // 2^n
	return pow(2,n);
} // end gnSeven()

int BigO::gnEight(int n) { // n!
	return (n == 1 || n == 0) ? 1 : gnEight(n - 1) * n;
} // end gnEight()

double BigO::gnNine(int n) { // n^(3/2)*logn
	double power = 1.5;
	return pow(n,power)*log(n);
} // end gnNine()