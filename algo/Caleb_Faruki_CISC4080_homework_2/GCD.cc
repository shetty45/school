/*********************************************************************
* Name: Caleb Faruki
* Professor: Dr. Xiaoxu Han
* Course: CISC 4080 Algorithms
* Date: November 14, 2013
* Description: Homework 2 GCD()
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int compute_gcd(int a, int b) {
	printf("\nComputing GCD for %d|%d",a,b);
	if(a%b == 0)
		return b; //clean division
	return compute_gcd(b, a%b);
} // end compute_gcd()

int main(int argc, char** argv) {
	int a, b, gcd =0;
	if (argc!=3) { /*<gcd> <a> <b>*/
		cout << "Error: Too few or too many arguments\n"
			 << "Please type './gcd <a> <b> to compute GCD(a,b)'" << endl;
		return 1;
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	if(a<b) { // swap a & b
		int temp = a;
		a = b;
    	b = temp;
	}
	printf("\nResults: GCD( %d, %d ) = %d\n\n",a,b,compute_gcd(a,b));
	return 0;
} // end main()