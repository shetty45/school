/*******************************************************
file: rsa_simulation.java
This is a sample program for CISC4080 Homework 4"
Author: Henry Han
********************************************************/
import java.io.*;
import java.math.BigInteger;
import java.util.Random;
public class rsa_simulation 
{
	public static void main(String[] args) throws IOException
	{
		// 1. Generate p,q; compute n
		BigInteger p=pseudo_prime(512, 100);
		BigInteger q=pseudo_prime(512, 100);
		BigInteger n_=p.multiply(q); //n_=p*q

		// 2. Compute phi(n)=(p-1)*(q-1)
		BigInteger p_minus_1=p.subtract(BigInteger.ONE);
		BigInteger q_minus_1=q.subtract(BigInteger.ONE);
		BigInteger phi_n=p_minus_1.multiply(q_minus_1);
		System.out.println("\n this is phi(n) \n"+phi_n);

		// 3. Select encrytion key e_	
		BigInteger e_=BigInteger.ONE;
		for( int i=3;i<100;i++) {
			BigInteger big_i=BigInteger.valueOf(i);
			BigInteger t=phi_n.gcd(big_i);
			if (t.equals(BigInteger.ONE)) {
				e_=big_i;
					break;
			}
		}

		System.out.println("\nThis is encrytion key: e_\n\n" +e_);

		//4. compute decrytion key d_
		BigInteger d_=e_.modInverse(phi_n);
		System.out.println("\nthis is the decrytion key: d_\n\n"+d_);

		//5. publish the public key
		System.out.println("\nThis is the public key:\n\n");
		System.out.println("("+e_.toString()+","+n_.toString()+")");

		// This is the message
		BigInteger m=pseudo_prime(256, 100);
		System.out.println("\nThis is the message:\n\n"+m);

		//6. Encrpytion
		BigInteger c=m.modPow(e_,n_);
		System.out.println("\n"+"This is the encrypted message:\n\n"+c);
	
		//7. decryption
		BigInteger m2=c.modPow(d_, n_);
		System.out.println("\nThis is the retrieved message:\n\n"+m2+"\n\n");
	}

// Generate a pseudo-prime number with # of bits: ’bit_length’
// The probability that this number is prime > 1-(1/2)^certainty
	public static BigInteger pseudo_prime(int bit_length, int certainty)
	{
		Random rnd=new Random();
		BigInteger p_prime=new BigInteger(bit_length, certainty, rnd);
		return p_prime;
	}
}
