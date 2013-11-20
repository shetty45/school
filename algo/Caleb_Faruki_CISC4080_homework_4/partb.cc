
#include <gmp.h>
#include <stdint.h>
//g++ myprogram.cc -lgmpxx -lgmp

void generate_PQ(mpz_t p, mpz_t q);
void compute_N(mpz_t n, mpz_t p, mpz_t q);
void compute_phiN(mpz_t phiN, mpz_t phiP, mpz_t phiQ, 
									mpz_t p, mpz_t q);

int main() 
{
	mpz_t p,q,n;
	mpz_init(p);
	mpz_init(q);
	mpz_init(n);

	// 1. Generate p,q; compute n
	generate_PQ(p,q);
	compute_N(n,p,q);

	mpz_t phiP, phiQ, phiN;
	mpz_init(phiP);
	mpz_init(phiQ);
	mpz_init(phiN);

	// 2. Compute phi(n)=(p-1)*(q-1)
	compute_phiN(phiN,phiP,phiQ,p,q);

	return 0;
}

void generate_PQ(mpz_t p, mpz_t q) 
{
	gmp_randstate_t rstate;
	gmp_randinit_default(rstate);

	uint8_t rep = 0;
	printf("Generating keys...\n\n");
	while(rep==0) { // 2=prime, 1=maybe prime 0=composite
		mpz_urandomb(p,rstate,1024);
		//args(mpz_t rop, int '# of tests')
		rep = mpz_probab_prime_p(p,1000);
	}
	printf("***************************P KEY**************************\n");
	gmp_printf("    %Zd\n",p);

	rep = 0;
	while(rep==0) { // 2=prime, 1=maybe prime 0=composite
		mpz_urandomb(q,rstate,1024);
		//args(mpz_t rop, int '# of tests')
		rep = mpz_probab_prime_p(q,1000);
	}
	printf("***************************Q KEY**************************\n");
	gmp_printf("    %Zd\n",q);
}

void compute_N(mpz_t n, mpz_t p, mpz_t q)
{
	mpz_mul(n,p,q);
	printf("\n*************************N = P x Q*************************\n");
	gmp_printf("    %Zd\n",n);
}

void compute_phiN(mpz_t phiN, mpz_t phiP, mpz_t phiQ, mpz_t p, mpz_t q)
{
	mpz_sub_ui(phiP,p,1);
	mpz_sub_ui(phiQ,q,1);
	mpz_mul(phiN,phiP,phiQ);
	printf("\n*******************phi(n) = (p-1)x(q-1)********************\n");
	gmp_printf("    %Zd\n",phiN);
}