/*********************************************************************
* Author: caleb Faruki
* Course: CISC 4080 Algorithms
* Professor: Dr. Xiaoxu Han
* Date: November 11, 2013
* Description: Quiz 9 Extra Cred Modular Exponentiation Program
*********************************************************************/
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int modpow(int a, int n, int m);

int main() {
	//P1
	//a,n,m = base of exp, exp, modulo
	int a = 2, n = 133, m = 17;
	printf("answer: x = %d\n",modpow(a,n,m));
	//P2
	a = 21,	n = 72,	m = 37;
	printf("answer: x = %d\n",modpow(a,n,m));

	return 0;
}

int modpow(int a, int n, int m) { //,exp,mod
	int R; //remainder
	int x = 1; //answer

	printf("Computing %d^%d(mod%d)...",a,n,m);
	cout << endl;

	while(n != 0) { //exponent is not 0
		R = n % 2; //a^n%m = a^(n-R) %m * a^R %m
		n = n/2; //decrement by n/2 until n=1
		if(R==1)
			x = (x*a % m);
		a = (a*a) % m; // change a to a^2 % m
		printf("R = %d, n = %d, a = %d",R,n,a);
		cout << endl;
	}
	return x; //solve for x = a^n mod(m)
}