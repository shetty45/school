/**********************************************************************
* Authors: Caleb Faruki
* Course: CISC4080 Algorithms
* Date: September 26, 2013
* File: Homework 1b insertSort()
**********************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <time.h>
#include <stdio.h>
using namespace std;

void insertSort(int *array, const int& length);

int main(int argc, char** argv) {

/***********AVERAGE CASE*********************/
	for(int i=1; i <= 6; i++) { 

		const int n = pow(10,i);

		int *randomArray = new int [n];
		const unsigned long N= 1000000;

		for(int i=0; i<n; i++)
			randomArray[i] = rand() % N;

		clock_t t = clock(); //takes starting time
		insertSort(randomArray, n);
		t = clock()-t; //subtracts start from finish time

		printf("It took %d clicks, (%f seconds) to"
			" sort this array of %d entries"
			" \n",(int) t,((float)t)/CLOCKS_PER_SEC, n);

		int print_bit=0; // 0: no printout

		if(print_bit) {
			for(int i=0; i<n; i++)
				cout<<"randomArray["<<i<<"] = "<<randomArray[i]<<endl;
		}
	delete randomArray;
	}

/***********BEST CASE****************/
	const int n = pow(10,6);
	int *sortedArray = new int[n];
	for(int i=0; i<n;i++)
		sortedArray[i] = n;

	clock_t t = clock();
	insertSort(sortedArray, n);
	t = clock()-t;

	printf("It took %d clicks, (%f secs) to sort a 10^6 array best case: \n",
		(int) t, ((float)t)/CLOCKS_PER_SEC,n);

	delete sortedArray;

/***********WORST CASE*************/
	int *worstArray = new int[n];
	int inverse = n;
	//the array is created in descending order.
	for(int i=0; i<n; i++) {
		worstArray[i] = inverse;
		inverse = n-i;
	}

	t = clock();
	insertSort(worstArray, n);
	t = clock()-t;

	printf("It took %d clicks, (%f secs) to sort a 10^6 array worst case: \n",
		(int) t, ((float)t)/CLOCKS_PER_SEC,n);

	delete worstArray;

/***The sorting time on a randomArray represents AVERAGE CASE****/
	return 0;
} // end main()

void insertSort(int *array, const int& length) {

	int key; //item to be sorted
	int j=0; //at beginning, the sorted array is length 0

	//scanning the whole array from the second one
	for(int i=1; i<length; i++) {
		key=array[i]; //the card to be inserted
		j=i; //the length of the sorted array (# sorted cards)
		//if the key > item on left
		//move key to the left until there is no item > key on the left.

		while(j>0 && key < array[j-1]) {
			array[j] = array[j-1]; //'swap' the smaller one to the right
			j-=1; 
		}
		array[j] = key; //j is index of the correct location for the key
	}
}
/* BEST: already sorted array
	WORST: backwardly sorted
	GENERAL: random array*/

