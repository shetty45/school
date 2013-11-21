
#include <gmp.h>
#include <stdint.h>
//g++ myprogram.cc -lgmpxx -lgmp

void generate_PQ(mpz_t p, mpz_t q);
void compute_N(mpz_t n, mpz_t p, mpz_t q);
void compute_phiN(mpz_t phiN, mpz_t phiP, mpz_t phiQ, 
									mpz_t p, mpz_t q);
void select_E(mpz_t e, mpz_t phiN);
void compute_D(mpz_t d, mpz_t e, mpz_t phiN);
void encrypt(mpz_t c, mpz_t msg, mpz_t e, mpz_t n);
void decrypt(mpz_t m2,mpz_t c,mpz_t d,mpz_t n);

int main() 
{
	// 1. Generate p,q; compute n
	mpz_t p,q,n; mpz_init(p); mpz_init(q); mpz_init(n);

	generate_PQ(p,q);
	compute_N(n,p,q);

	// 2. Compute phi(n)=(p-1)*(q-1)
	mpz_t phiP, phiQ, phiN;
	mpz_init(phiP); mpz_init(phiQ); mpz_init(phiN);

	compute_phiN(phiN,phiP,phiQ,p,q);

	// 3. Select encryption key e
	mpz_t e; mpz_init(e); mpz_set_str(e,"1",10);

	select_E(e,phiN);

	// 4. Compute decryption key d
	mpz_t d; mpz_init(d);

	compute_D(d,e,phiN);

	// 5. Publish public key

	// msg = message to be encrypted
	mpz_t msg; mpz_init(msg);
	mpz_set_str(msg,"1234567890",10);

	// 6. c = encrypted message
	mpz_t c; mpz_init(c);
	encrypt(c,msg,e,n);

	// 7. m2 = decrypted message 
	mpz_t m2; mpz_init(m2);
	decrypt(m2,c,d,n);

	return 0;
}

void generate_PQ(mpz_t p, mpz_t q) 
{
	gmp_randstate_t rstate;
	gmp_randinit_default(rstate);

	uint8_t repeat = 0;
	printf("\nGenerating keys...\n");
	while(repeat==0) { // 2=prime, 1=maybe prime 0=composite
		mpz_urandomb(p,rstate,64);
		//args(mpz_t rop, int '# of tests')
		repeat = mpz_probab_prime_p(p,255);
	}
	
	printf("\n***** p KEY *****\n");
	gmp_printf("    %Zd\n",p);

	repeat = 0;
	while(repeat==0) { // 2=prime, 1=maybe prime 0=composite
		mpz_urandomb(q,rstate,64);
		//args(mpz_t rop, int '# of tests')
		repeat = mpz_probab_prime_p(q,255);
	}
	
	printf("\n***** q KEY *****\n");
	gmp_printf("    %Zd\n",q);
}

void compute_N(mpz_t n, mpz_t p, mpz_t q)
{
	mpz_mul(n,p,q);
	
	printf("\n***** n = p x q *****\n");
	gmp_printf("    %Zd\n",n);
}

void compute_phiN(mpz_t phiN, mpz_t phiP, mpz_t phiQ, mpz_t p, mpz_t q)
{
	mpz_sub_ui(phiP,p,1); //phi(p) = p-1
	mpz_sub_ui(phiQ,q,1); //phi(q) = q-1
	//phi(n)=phi(p)*phi*(q)
	mpz_mul(phiN,phiP,phiQ);
	
	printf("\n***** phi(n) = (p-1)x(q-1) *****\n");
	gmp_printf("    %Zd\n",phiN);
}

void select_E(mpz_t e, mpz_t phiN)
{
	for(uint8_t i=3;i<100;i++) {
		mpz_t t;
		mpz_init(t);
		mpz_gcd_ui(t,phiN,i);
		if(mpz_cmp_ui(t,1)==0) //if t==1, phi(n),i share no factors
			mpz_set_ui(e,i); // e = i
	}
	printf("\n***** e KEY *****\n");
	gmp_printf("    %Zd\n",e);
}

void compute_D(mpz_t d, mpz_t e, mpz_t phiN)
{
	mpz_powm_ui(d,e,-1,phiN); // d = e^-1 mod phiN
	
	printf("\n***** d KEY *****\n");
	gmp_printf("    %Zd\n",d);
}

void encrypt(mpz_t c, mpz_t msg, mpz_t e, mpz_t n)
{
	mpz_powm(c,msg,e,n); /* c = msg^e(mod n) */

	printf("\n************************************ msg ***********************************\n");
	gmp_printf("    %Zd\n",c);
}

void decrypt(mpz_t m2,mpz_t c,mpz_t d,mpz_t n)
{
	mpz_powm(m2,c,d,n); //msg = c ^ d (mod n)
	printf("\n************************************ msg2 ***********************************\n");
	gmp_printf("    %Zd\n",m2);
}