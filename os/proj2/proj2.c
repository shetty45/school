/*********************************************************************
* Name: Caleb Faruki
* Professor: Dr. Art Werschulz
* Course: CISC3595 Operating Systems
* Date: November 14, 2013
* Description: Proj2 Pthread Fib Computer
*********************************************************************/
#include <cstdlib>
#include <cstdio>
#include <pthread.h>
#include <iostream>

unsigned long int fibonacci(unsigned long int n);
void *fibrun (void *param);

unsigned long int *fiba; // fib array
int n; // equiv. to 'upper' in fig 4.9

int main(int argc, char* argv[]) {
	pthread_t tfib;
	pthread_attr_t attr;

	if(argc != 2) {
		fprintf(stderr,"usage: proj2 <integer>\n");
		return 1;
	}
	n = atoi(argv[1]);
	if(n<0 || n>=47) {
		fprintf(stderr,"condition not met: 0 < %d >= 47\n",n);
		return 2;
	}

    fiba = new unsigned long int[47];
    //initiate child thread
	pthread_attr_init(&attr);
	pthread_create(&tfib,&attr,fibrun,NULL); // argv[1] = n
	pthread_join(tfib,NULL);
	// back to parent thread
	for(int i=0; i < n; i++)
		printf("fibs[ %d] = %lu\n",i,fiba[i]);

	return 0;
} // end main()

unsigned long int fibonacci(int n) {
/*	int array[n+1];
	array[0] = 0;
	array[1] = 1;*/
	for(int i; i<2; i++)
		array[i] = i;
	if(n<2) {
		cout << "FJUGHIEUGE" << endl;
		return array[n]; }
	for(int i=2; i <= n; i++)
		array[i]=array[i-1]+array[i-2];

	return array[n];
} // end fibonacci ()

// fibrun calls fibonacci() once for each array entry
void *fibrun (void *param) {
	for(int i=1; i < n; i++)
		fiba[i] = fibonacci(i);
	// return(0) to parent
	pthread_exit(0);
} // end fib_runner()

/*********************************************************************
* This program is written on a Linux 32-bit platform. Input exceeding
* n=47 will overflow and compute incorrect fibonacci numbers for n>47
*********************************************************************/