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

void *fib_runner (void *param);

unsigned long int *fib_array;
int upper;

int main(int argc, char** argv) {
	pthread_t tid;
	pthread_attr_t attr;

	if(argc != 2) {
		fprintf(stderr,"usage: fib <integer>\n");
		return 1;
	}
	upper = atoi(argv[1]);
	if(upper<0 || upper>=256) {
		fprintf(stderr,"condition not met: 0 < %d >= 255\n",upper);
		return 2;
	}

	/* get default attributes */
	pthread_attr_init(&attr);
	/*create the thread */
	pthread_create(&tid,&attr,fib_runner,argv[1]);
	/*wait for thread to exit */
	pthread_join(tid,NULL);

	for(int i=0; i < upper; i++)
		printf("fibs[ %d] = %d\n",i,fibarray);

	return 0;
}

void *fib_runner (void *param) {
	int i, upper = atoi(param);
	fib = 0;
	for (i=1; i<= upper; i++)
		fibarray += i;

	pthread_exit(0);
}