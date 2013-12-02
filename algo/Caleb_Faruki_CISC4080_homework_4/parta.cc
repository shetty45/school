#include <stdint.h>
#include <stdio.h>
#include <math.h>

using namespace std;

bool isPrime(uint64_t n); //naive primality test
void print(bool prime, uint64_t n); //print primality

int main () 
{
	uint64_t a=107,
					 b=1187,
					 c=2312,
					 d=7091,
					 e=95171,
					 f=177111,
					 g=8992231,
					 h=20131107;
	print(isPrime(a),a);
	print(isPrime(b),b);
	print(isPrime(c),c);
	print(isPrime(d),d);
	print(isPrime(e),e);
	print(isPrime(f),f);
	print(isPrime(g),g);
	print(isPrime(h),h);
	return 0;
}

bool isPrime(uint64_t n) 
{
	//waste of time
	if(n < 4) {
		fprintf(stderr,"Trivially prime.\n");
		return true;
	}
	//even #, not prime
	else if(n%2==0) {
		return false;
	}
	//check if divisible by all odd #s < sqrt(n)
	for(uint64_t i=3; i<(uint64_t)sqrt(n+1); i+=2) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

long powmod(uint64_t a, uint64_t exp, uint64_t n)
{
  long long int b=1;
  while (exp) {
   	if (exp%2==0) {
      	exp/=2;
      	a = (a*a)%n;
     	}
    	else {
      	exp--;
      	b = (b*a)%n;
      }
  }
  return b;
}

void print(bool prime, uint64_t n) 
{
	if(prime)
		printf("%llu is prime.\n",n);
	else
		printf("%llu is NOT prime!\n",n);
}