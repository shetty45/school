/* ********************************************************************
 *
 *
 *
 *
 * ********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//int array[300];
long int fibRec(long int n);
unsigned long long int fib(unsigned long long int n); /* calculate fibonacci */
void *fibonacci(void *param); /* thread starts here */

unsigned long long int *array; /* array to handle input */
int upper;

int main(int argc, const char *argv[]) {

    pthread_t thread1; /* allows for the thread to be identified */
    pthread_attr_t attr; /* set of thread attributes */

    /* sanity checking */
    if (argc != 2) {
        fprintf(stderr, "Usage: proj2 <integer value>\n");
        return 1;
    }
    upper = atoi(argv[1]); /* convert */
    //upper = atol(argv[1]); /* convert  */

    if (upper >= 256 || upper < 0 ) {
        fprintf(stderr, "argument %d must be >= 0 < 256\n", upper);
        return 2;
    }

    /* allocate memory for array to size of input + 1 */
    array = (unsigned long long int*)
            malloc((upper + 1)*sizeof(unsigned long long int));

    pthread_attr_init(&attr); /* get default attributes */
    pthread_create(&thread1,&attr,fibonacci,NULL); /*create the thread param:NULL*/
    pthread_join(thread1,NULL); /* wait for thread to exit*/

    int i;
    for (i=0; i < upper; i++) {
        printf("fibs[  %d] = %d\n", i, array[i]);
        }
    free(array); /* release the memory */
    return 0;
}

long int fibRec(long int n) {
    if (n < 2)
        return n;
    else
        return fibRec(n-1) + fibRec(n-2);
}

/* optimized fibonacci function*/
unsigned long long int fibo(unsigned long long int n) {
    int a[n+1]; /* array to store fibo numbers */

    a[0] = 0; /* first position of fibo series array is 0 */
    a[1] = 1; /* second position of fibo series array is 1 */

    int i;
    for (i=2; i <= n; i++) { /* start at position two of array */
        /* add last two positions of the series, 0,1,1,2,n-1 + n-2,... */
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}

/* The thread will begin control in this function */
void *fibonacci(void *param) {
    int i;
    for(i=0; i < upper; i++) {
        array[i] = fibo(i);
    }
    pthread_exit(0); /* thread exits */
}