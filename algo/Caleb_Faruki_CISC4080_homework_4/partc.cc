#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <gmpxx.h>
#include <string>
#include <time.h>
//g++ myprogram.cc -lgmpxx -lgmp
using namespace std;

void generate_pq(mpz_t& p, mpz_t& q);
void compute_n(mpz_t n, const mpz_t p, const mpz_t q);
void compute_phiN(mpz_t phi_n, const mpz_t p, const mpz_t q);
void select_e(mpz_t e, const mpz_t phi_n);
void compute_d(mpz_t d, const mpz_t e, const mpz_t phi_n);
bool isPrime(const mpz_t bignum)
{
	mpz_t modnum; mpz_init(modnum);
	if(mpz_cmp_ui(bignum,4)<0 && mpz_cmp_si(bignum,0)>=0) {
		fprintf(stderr,"Trivially prime.\n");
		return false;
	}
	else if(mpz_mod_ui(modnum,bignum,2)==0)
		return false;
	mpz_clear(modnum);

	mpz_t i,rootnum; 
	mpz_inits(i,modnum,rootnum,NULL);
	mpz_sqrt(rootnum,bignum);
	mpz_set_str(i,"3",10);

	for(;mpz_cmp(rootnum,i)>0; mpz_add_ui(i,i,2)) {
		mpz_mod(modnum,bignum,i);
		if(mpz_cmp_ui(modnum,0)==0)
			return false;
	}
	mpz_clears(modnum,i,rootnum,NULL);
	return true;
}

int main() 
{
	mpz_t p, q, n, phi_n, e, d; 
	mpz_inits(p, q, n, phi_n, e, d, NULL);

	// 1. Generate p,q; compute n
	generate_pq(p,q);
	compute_n(n,p,q);
	// 2. Compute phi(n)=(p-1)*(q-1)
	compute_phiN(phi_n,p,q);
	mpz_clears(p,q,NULL);
	// 3. Select encryption key e
	select_e(e,phi_n);
	// 4. Compute decryption key d
	compute_d(d,e,phi_n);
	mpz_clear(phi_n);
	// 5. m = message to be encrypted
	printf("\nMessage: ");

	char* buffer = new char[64];
	cin.getline(buffer,64);
	int size = strlen(buffer);
	mpz_t* m = new mpz_t[size];
	for(int i=0; i<size; i++) {
		mpz_init(m[i]);
		mpz_set_ui(m[i],(int)buffer[i]);
	}
	delete buffer;

	// 6. c = encrypted message
	mpz_t* c = new mpz_t[size];
	for(int i=0; i<size; i++) {
		mpz_init(c[i]);
		mpz_powm(c[i], m[i], e, n);
		mpz_clear(m[i]);
	} /* c = m^e(mod n) */
	delete m;
	string cipher;
	for(int i=0; i<size; i++)
		cipher += (char)mpz_get_ui(c[i]);
	cout << "\nCipher: " << cipher << endl;
	// 7. m2 = decrypted message 
	mpz_t* m2 = new mpz_t[size];
	for(int i=0; i<size; i++) {
		mpz_init(m2[i]);
		mpz_powm(m2[i],c[i],d,n);
		mpz_clear(c[i]);
	} /* m = c ^ d (mod n) */
	delete c;
	// 8. print m2
	string message;
	for(int i=0; i<size; i++)
		message += (char)mpz_get_ui(m2[i]);
	cout << "\nDecrypted Message: " << message << endl;
	return 0;
}

void generate_pq(mpz_t& p, mpz_t& q) 
{
	gmp_randstate_t rstate;
	gmp_randinit_default(rstate);
	gmp_randseed_ui(rstate,time(NULL));

	printf("\nGenerating keys...\n");
	do {
		mpz_urandomb(p,rstate,1024);
	} while(!isPrime(p));
	printf("\n***** p *****\n");
	gmp_printf("    %Zd\n",p);
	do {
		mpz_urandomb(q,rstate,1024);
	} while(!isPrime(q));
	gmp_randclear(rstate);
	
	printf("\n***** q *****\n");
	gmp_printf("    %Zd\n",q);
}

void compute_n(mpz_t n, const mpz_t p, const mpz_t q)
{
	mpz_mul(n,p,q);
	
	printf("\n***** n = p x q *****\n");
	gmp_printf("    %Zd\n",n);
}

void compute_phiN(mpz_t phi_n, const mpz_t p, const mpz_t q)
{
	mpz_t phi_p, phi_q;
	mpz_inits(phi_p,phi_q,NULL);

	mpz_sub_ui(phi_p,p,1); //phi(p) = p-1
	mpz_sub_ui(phi_q,q,1); //phi(q) = q-1
	//phi(n)=phi(p)*phi*(q)
	mpz_mul(phi_n,phi_p,phi_q);
	mpz_clears(phi_p,phi_q,NULL);
	
	printf("\n***** phi(n) = (p-1)x(q-1) *****\n");
	gmp_printf("    %Zd\n",phi_n);
}

void select_e(mpz_t e, const mpz_t phi_n)
{ /* e = encryption key */
	for(uint8_t i=3;i<100;i++) {
		mpz_t t;
		mpz_init(t);
		mpz_gcd_ui(t,phi_n,i);
		if(mpz_cmp_ui(t,1)==0) //if t==1, phi(n),i share no factors
			mpz_set_ui(e,i); // e = i
	}
	printf("\n***** e *****\n");
	gmp_printf("    %Zd\n",e);
}

void compute_d(mpz_t d, const mpz_t e, const mpz_t phi_n)
{ /* d = decryption key */
	mpz_invert(d,e,phi_n); // d = e^-1 mod phi_n
	
	printf("\n***** d *****\n");
	gmp_printf("    %Zd\n",d);
}