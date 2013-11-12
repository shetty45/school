/**********************************************************************
* Authors: Caleb Faruki
* Course: CISC4080 Algorithms
* Date: September 26, 2013
* File: Homework 1b Question 3
**********************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <time.h>
#include <stdio.h>
using namespace std;

int fOne(int);

int gOne(int);

int main() {
/*	int n = 1;
	bool flag = false;
	while(!flag) {
		if(fOne(n) > gOne(n))
			flag = true;
		else
			n++;
	}
	printf("f(n) overtakes g(n) after %d entries.\n",n);*/
	int n;
	for(int i=1; i<100; i++) {
		n=i;
		if(fOne(n) >= gOne(n)) {
			printf("f(%d) > g(%d) where f-g = ",n,n);
			cout << fOne(n) << endl;
		} else if(gOne(n) >= fOne(n)) {
			printf("g(%d) > f(%d) where f-g = ",n,n);
			cout << (gOne(n)-fOne(n)) << endl;
		}
	}
	cout << "The growing gap b/t f(n) and g(n) shows that f(n) reaches"
			" infinite faster.\n" << endl;
	return 0;
}

int fOne(int n) { return pow(n,3); }

int gOne(int n) { return (pow(n,1.5)*log10(n)); }