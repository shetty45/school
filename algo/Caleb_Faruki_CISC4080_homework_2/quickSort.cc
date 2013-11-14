/*********************************************************************
* Name: Caleb Faruki
* Professor: Dr. Xiaoxu Han
* Course: CISC 4080 Algorithms
* Date: November 12, 2013
* Description: Homework 2 quickSort()
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

void printArray(int a[], int size);
void avg(int a[], int size);
void best(int a[], int size);
void worst(int a[], int size);

bool isSorted(const int a[], int& size) {
	for(int i=0; i < size-1; i++) {
		if(a[i] > a[i+1])
			return false;
	} // want ascending order, not descending
	for(int i=0; i < size-1; i++) {
		if(a[i] < a[i+1])
			return true;
	}
} // end isSorted()

void swap(int& x, int& y) {
    int temp = x; // create temp copy of x
    x = y; // overwrite original x
    y = temp; // copy temp into y
} // end swap()

int choosePivot(int a[], int lo, int hi) {
    int mid = ((hi-lo)/2);

    if((a[hi] < a[lo]) && (a[hi] < a[mid]))
		return hi;
    else if((a[lo] < a[hi]) && (a[lo] < a[mid]))
		return lo;
    else
		return mid;
} // end choosePivot()

void partition(int a[], int lo, int hi, int& pivotIndex) {
    choosePivot(a, lo, hi);

    int pivot = a[lo];
    int lastS1 = lo;
    int firstUnknown = lo + 1;

    for(; firstUnknown <= hi; ++firstUnknown) {
		if(a[firstUnknown] < pivot) {
		    ++lastS1;
		    if (firstUnknown != lastS1)
				swap(a[firstUnknown], a[lastS1]);
		}
    }

//place pivot in proper position and mark its loc.
    if (firstUnknown != lastS1)
	swap(a[lo], a[lastS1]);
    pivotIndex = lastS1;
} // end partition()

void quickSort(int a[], int lo, int size) {
    int pivotIndex;
    int hi = size-1;

    if(!isSorted(a,size)) {
    	if(lo < hi) {
			partition(a, lo, hi, pivotIndex);
			quickSort(a, lo, pivotIndex-1);
			quickSort(a, pivotIndex+1, hi);
    	}
    }
} // end quickSort()

int main() {
	int size = pow(10,4);
	int* array = new int[size];

	best(array, size);
	if(isSorted(array,size))
    	cout << "\nArray in ascending order." << endl;

	clock_t time = clock();
	quickSort(array, 0, size);
	time = clock()-time;
	cout << "Best-case quickSort() took: "
		 << (int)time/(CLOCKS_PER_SEC/1000) << "ms\n"  << endl;

	worst(array, size);
	cout << "Array in descending order." << endl;

	time = clock();
	quickSort(array, 0, size);
	time = clock()-time;
	cout << "Worst-case quickSort() took: "
		 << (int)time/(CLOCKS_PER_SEC/1000) << "ms\n"  << endl;

	avg(array, size);
	cout << "Array of random entries." << endl;

	time = clock();
	quickSort(array, 0, size);
	time = clock()-time;
	cout << "Average-case quickSort() took: "
		 << (double)time/(CLOCKS_PER_SEC/1000) << "ms\n"  << endl;

	return 0;
} // end main()

//for debugging purposes
void printArray(int a[], int size) {
	for(int i=0; i < size; i++)
		cout << " " << a[i] << endl;
} // end printArray()

void avg(int a[], int size) { //avg-case sort
	srand((unsigned)time(0));
	for(int i=0; i < size; i++)
		a[i] = rand()%10+1;
} // end avg()

void best(int a[], int size) { //best-case sort
	for(int i=0; i < size; i++)
		a[i] = i;
} // end best()

void worst(int a[], int size) { //worst-case sort
	int m = size;
	for(int i=0; i < size; i++, m--)
		a[i] = m;
} // end worst()