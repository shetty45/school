#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

using namespace std;

void generate_pq(int &p,int &q);
void compute_n(int &n, const int p, const int q);
void compute_phiN(int &phi_n, const int p, const int q);
void select_e(int &e, const int phi_n);
void compute_d(int &d, int e, const int phi_n);

int powmod(int b, int e, int m);

int main() 
{
	int p,q;
	int n,phi_n,e=0,d;
	// 1. Generate p,q; compute n
	generate_pq(p,q);
	compute_n(n,p,q);
	// 2. Compute phi(n)=(p-1)*(q-1)
	compute_phiN(phi_n,p,q);
	// 3. Select encryption key e
	select_e(e,phi_n);
	// 4. Compute decryption key d
	compute_d(d,e,phi_n);
	// 5. m = message to be encrypted
	printf("\nMessage: ");

	char* buffer = new char[1024];
	cin.getline(buffer,1024);
	int size = strlen(buffer);

	int* m = new int[size];
	for(int i=0; i<size; i++)
		m[i] = buffer[i];
	delete buffer;

	// 6. c = encrypted message
	int* c = new int[size];
	for(int i=0; i<size; i++) {
		c[i] = powmod(m[i],e,n);
	} // c = m^e(mod n)
	delete m;

	string cipher;
	for(int i=0; i<size; i++)
		cipher += (char)c[i];
	cout << "\nCipher: " << cipher << endl;

	// 7. m2 = decrypted message 
	int* m2 = new int[size];
	for(int i=0; i<size; i++) {
		m2[i] = powmod(c[i],d,n);
	} // m = c ^ d (mod n)
	delete c;

	// 8. print m2
	string decrypted;
	for(int i=0; i<size; i++)
		decrypted += (char)m2[i];
	cout << "\nDecrypted Message: " << decrypted << endl;
}

bool isPrime(int n) 
{
	//waste of time
	if(n < 2)
		return false;
	//even #, not prime
	else if(n%2==0)
		return false;
	//check if divisible by all odd #s < sqrt(n)
	for(int i=3; i <= sqrt(n); i=i+2) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

int gcd(int a, int b) {
	int temp;
   while (b!=0) {
   	temp = b;
   	b = a%b;
   	a = temp;
    }
    return a;
}

int powmod(int b, int e, int m) 
{
    int r; // remainder
    int x = 1;
    while(e != 0) {
        r = e%2;
        e = e/2;        
        if(r==1)
            x = (x*b)%m;
        b = (b*b)%m;
    }
    return x;
}

void generate_pq(int &p, int &q)
{
	srand(time(NULL));
	bool repeat = false;
	printf("\nGenerating keys...\n");

	while(!repeat) {
		p = rand()%100;
		repeat = isPrime(p);
	}
	repeat = false;
	while(!repeat) {
		q = rand()%100;
		repeat = isPrime(q);
	}
	printf("\n***** p *****\n%u\n\n***** q *****\n%u\n",p,q);
}

void compute_n(int &n, const int p, const int q)
{
	n = p * q;
	printf("\n***** n = p x q *****\n%u\n",n);
}

void compute_phiN(int &phi_n, const int p, const int q)
{
	phi_n = (p-1) * (q-1);
	printf("\n***** phi(n) = (p-1)x(q-1) *****\n%u\n",phi_n);
}

void select_e(int &e, const int phi_n)
{ // e = encryption key
	for(int i=3;i<100;i++) {
		if(gcd(phi_n,i) == 1) {
			e = i;
			break;
		}
	}
	printf("\n***** e *****\n%u\n",e);
}

void compute_d(int &d, int e, const int phi_n)
{ // d = decryption key
	d = powmod(e,-1,phi_n);
	int num; // numerator
	for(int i=1; ;++i) {
		num = phi_n * i + 1;
		if(num%e==0)
			break;
	} // d = e^-1 mod phi_n
	d = num/e;
	printf("\n***** d *****\n%u\n",d);
}