/*********************************************************************
* Name: Caleb Faruki
* Professor: Dr. Art Werschulz
* Course: CISC3595 Operating Systems
* Date: November 14, 2013
* Description: Proj2 Fibonacci
*********************************************************************/
#include <cstdlib>
#include <cstdio>
#include <pthread.h>
#include <iostream>

int fibonacci(int n);
void *fibrunner (void *param);

int *array;
int fib;
int n; // equivalent to 'upper' in fig 4.9

int main(int argc, char* argv[]) {
	pthread_t tfib;
	pthread_attr_t attr;

	if(argc != 2) {
		fprintf(stderr,"usage: proj2 <integer>\n");
		return 1;
	}
	n = atoi(argv[1]);
	if(n<0 || n>=256) {
		fprintf(stderr,"condition not met: 0 < %d >= 255\n",n);
		return 2;
	}
	pthread_attr_init(&attr);
	pthread_create(&tfib,&attr,fibrunner,NULL); // argv[1] = n
	pthread_join(tfib,NULL); //SEG FAULT HERE!!!!

/*	std::cout << 2 << std::endl;
	// print fib_runner results as they are computed
	for(int i=0; i < n; i++)
		printf("fibs[ %d] = %d\n",i,array[i]);*/

	return 0;
} // end main()

int fibonacci(int n) {
	int array[n+1];
	array[0] = 0;
	array[1] = 1;
	for(int i=2; i <= n; i++)
		array[i]=array[i-1]+array[i-2];
	return array[n];
} // end fibonacci ()

void *fibrunner (void *param) {
	for(int i=1; i < n; i++)
		array[i] = fibonacci(i);

	pthread_exit(0);
} // end fib_runner()

/*
if(n<2)
	return n;
int prePrev=0, prev=1, result=0;

for(int i=2; i<=n; i++) {
	sum = prePrev + prev;
	prePrev = prev;
	prev = sum;
}
return sum;
*/