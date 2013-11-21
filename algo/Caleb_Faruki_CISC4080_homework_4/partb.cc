#include <stdint.h>
#include <iostream>
#include <stdio.h>
#include <gmpxx.h>
//g++ myprogram.cc -lgmpxx -lgmp
using namespace std;

void generate_pq(mpz_t p, mpz_t q);
void compute_n(mpz_t n, const mpz_t p, const mpz_t q);
void compute_phiN(mpz_t phi_n, const mpz_t p, const mpz_t q);
void select_e(mpz_t e, mpz_t phi_n);
void compute_d(mpz_t d, mpz_t e, mpz_t phi_n);
void store_m(mpz_t m[], int& size);
void encrypt(mpz_t c[], mpz_t m[], const int size, 
				 const mpz_t e, const mpz_t n);
void decrypt(mpz_t m2[], mpz_t c[], const int size, 
				 const mpz_t d, const mpz_t n);

int main() 
{
	mpz_t p, q, n, phi_n, e, d; 
	mpz_inits(p, q, n, phi_n, e, d, NULL);

	// 1. Generate p,q; compute n
	generate_pq(p,q);
	compute_n(n,p,q);
	// 2. Compute phi(n)=(p-1)*(q-1)
	compute_phiN(phi_n,p,q);
	mpz_clear(p); mpz_clear(q);
	// 3. Select encryption key e
	select_e(e,phi_n);
	// 4. Compute decryption key d
	compute_d(d,e,phi_n);
	// 5. m = message to be encrypted
	mpz_t* m;
	int size=0;
	store_m(m,size);
	// 6. c = encrypted message
	mpz_t* c;
	encrypt(c,m,size,e,n);
	// 7. m2 = decrypted message 
	//mpz_t* m2;
	//decrypt(m2,c,size,d,n);
	return 0;
}

void generate_pq(mpz_t p, mpz_t q) 
{
	gmp_randstate_t rstate;
	gmp_randinit_default(rstate);

	uint8_t repeat = 0;
	printf("\nGenerating keys...\n");
	while(repeat==0) {
		mpz_urandomb(p,rstate,64);
		//args(mpz_t rop, int '# of tests')
		repeat = mpz_probab_prime_p(p,10);
	}
	
//	printf("\n***** p *****\n");
//	gmp_printf("    %Zd\n",p);

	repeat = 0;
	while(repeat==0) { // 2=prime, 1=maybe prime 0=composite
		mpz_urandomb(q,rstate,64);
		//args(mpz_t rop, int '# of tests')
		repeat = mpz_probab_prime_p(q,10);
	}
	
//	printf("\n***** q *****\n");
//	gmp_printf("    %Zd\n",q);
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

	mpz_clear(phi_p); mpz_clear(phi_q);
	
	printf("\n***** phi(n) = (p-1)x(q-1) *****\n");
	gmp_printf("    %Zd\n",phi_n);
}

void select_e(mpz_t e, mpz_t phi_n)
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

void compute_d(mpz_t d, mpz_t e, mpz_t phi_n)
{ /* d = decryption key */
	mpz_powm_ui(d,e,-1,phi_n); // d = e^-1 mod phi_n
	
	printf("\n***** d *****\n");
	gmp_printf("    %Zd\n",d);
}

void store_m(mpz_t m[], int& size) 
{ /* m = original message */
	printf("Message: ");
	char* buffer = new char[128];
	cin.getline(buffer,128);
	size = strlen(buffer); //size = buffer
	m = new mpz_t[size];
	for(int i=0; i<size; i++) {
		mpz_init(m[i]);
		mpz_set_ui(m[i],(int)buffer[i]);
	}
}

void encrypt(mpz_t c[], mpz_t m[], const int size, 
				 const mpz_t e, const mpz_t n)
{ /* c = cipher */
	c = new mpz_t[size];
	for(int i=0; i<size; i++) {
		mpz_init(c[i]);
		mpz_powm(c[i],m[i],e,n);
		mpz_clear(m[i]);
	} /* c = m^e(mod n) */
//	printf("\n***** c *****\n");
//	gmp_printf("    %Zd\n",c);
}

void decrypt(mpz_t m2[], mpz_t c[], const int size, 
				 const mpz_t d, const mpz_t n)
{ /* m2 = decrypted message */
	m2 = new mpz_t[size];
	for(int i=0; i<size; i++) {
		mpz_init(m2[i]);
		mpz_powm(m2[i],c[i],d,n);
		mpz_clear(c[i]);
	} /* m = c ^ d (mod n) */

	printf("\n***** m2 *****\n");
	gmp_printf("    %Zd\n",m2);
}