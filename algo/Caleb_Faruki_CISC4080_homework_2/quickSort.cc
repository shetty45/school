/*********************************************************************
* Name: Caleb Faruki
* Professor: Dr. Xiaoxu Han
* Course: CISC 4080 Algorithms
* Date: November 12, 2013
* Description: Homework 2
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

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
}

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
} // partition()

void quickSort(int a[], int lo, int hi) {

    int pivotIndex;

    if(lo < hi) {
	partition(a, lo, hi, pivotIndex);

	quickSort(a, lo, pivotIndex-1);
	quickSort(a, pivotIndex+1, hi);
    }
} // end quickSort()

bool isSorted(int a[], int size) {
	for(int i=0; i < size-1; i++) {
		if(a[i] > a[i+1]) {
			cout << "Array is not sorted." << endl;
			return false;
		}
	}
	for(int i=0; i < size-1; i++) {
		if(a[i] < a[i+1]) {
			cout << "Array is sorted." << endl;
			return true;
		}
	}
} // end isSorted()

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
	int n = 0;
	for(int i=0; i < size; i++) {
		a[i] = n;
		n++;
	}
} // end best()

void worst(int a[], int size) { //worst-case sort
	int m = size;
	for(int i=0; i < size; i++) {
		a[i] = m;
		m--;
	}
} // end worst()

int main() {
	int size = 16384;
	int* array = new int[size];

	avg(array, size);
	cout << "\nCheck if avg-case array is sorted." << endl;
	isSorted(array, size);

	clock_t time = clock();
	quickSort(array, 0, size-1);
	time = clock()-time;
	cout << "Average-case quickSort() took: "
		 << (double)time/(CLOCKS_PER_SEC/1000) << "ms"  << endl;
	isSorted(array, size);

	worst(array, size);
	cout << "\nCheck if worst-case array is sorted." << endl;
	isSorted(array, size);

	time = clock();
	quickSort(array, 0, size-1);
	time = clock()-time;
	cout << "Worst-case quickSort() took: "
		 << (int)time/(CLOCKS_PER_SEC/1000) << "ms"  << endl;
	isSorted(array, size);

	best(array, size);
	cout << "\nCheck if best-case is sorted." << endl;
	isSorted(array, size);

	time = clock();
	quickSort(array, 0, size-1);
	time = clock()-time;
	cout << "Best-case quickSort() took: "
		 << (int)time/(CLOCKS_PER_SEC/1000) << "ms"  << endl;
	isSorted(array, size);

	cout << endl;
	return 0;
}