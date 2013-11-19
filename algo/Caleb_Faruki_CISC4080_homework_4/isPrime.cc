#include <cmath>
#include <gmp.h>
#include <cstdio>
#include <cstdlib>
//g++ myprogram.cc -lgmpxx -lgmp
//g++ myprogram.cc -o myprogram.exe -lgmpxx -lgmp
using namespace std;

bool isPrime(int n, int steps) {
	//waste of time
	if(n < 4) {
		fprintf(stderr,"Trivially prime.\n");
		steps++;
		return true;
	}
	//even #, not prime
	else if(n%2==0) {
		steps++;
		return false;
	}
	//check if divisible by all odd #s < sqrt(n)
	for(int i=3; i<sqrt(n); i+=2) {
		if(n%i==0) {
			steps++;
			return false;
		}
	}
	steps++;
	return true;
}
int main () {
	int num_primes = 0; //count # of primes
	int steps = 0; // count steps

	mpz_t sqrt_min, sqrt_max;
	mpz_init(sqrt_min);
	mpz_init(sqrt_max); 

	//sqrt(2^100)=2^50, sqrt(2^200)=2^100
	mpz_ui_pow_ui(sqrt_min,2,50);
	mpz_ui_pow_ui(sqrt_max,2,100);

	gmp_printf("min: %Zd\n",sqrt_min);
	gmp_printf("max: %Zd\n\n",sqrt_max);

	while(mpz_cmp_ui(sqrt_min,sqrt_max)<0) {
		
	}
//	mpz_class i = 0;
//	mpz_class sqrt_n;
//	for() {}
//		if(isPrime(i,steps)) {
//			num_primes++;
//			printf("Naive prime test for %Zd took %d steps.\n",i,steps);
//		}
	return 0;
}

//for(i;/*bool to check i)