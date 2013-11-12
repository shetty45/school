#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void swap(int& x, int& y) {
    int temp = x; // create temp copy of x
    x = y; // overwrite original x
    y = temp; // copy temp into y
} // end swap()

void partition(int a[], int lo, int hi, int& pivInd) {
    //choose midpoint as pivot
    int mid = ((hi-lo)/2);
    int pivot = a[mid];
    int lastS1 = lo;
    int firstUnknown = lo + 1;

    for(; firstUnknown <= hi; ++firstUnknown) {
		if(a[firstUnknown] < pivInd) {
	    	++lastS1;
	    	swap(a[firstUnknown], a[lastS1]);
		}
    }
    //place pivot index in proper pos and mark its loc.
    swap(a[lo], a[lastS1]);

    pivInd = lastS1;
} // partition()

void quickSort(int a[], int lo, int hi) {
    int pivInd; // initialize in scope.

    if(lo < hi) {
	partition(a, lo, hi, pivInd);//split in half
	quickSort(a, lo, pivInd-1); //sort 1st half
	quickSort(a, pivInd+1, hi); //sort 2nd half
    }
} // end quickSort()

bool isSorted(int a[], int size) {
	for(int i=0; i < size; i++) {
		if(a[i] > a[i+1]) {
			cout << "Array is not sorted." << endl;
			return false;
		}
	cout << "Array is sorted." << endl;
	return true;
	}
} // end isSorted()

void printArray(int a[], int size) {
	for(int i=0; i < size; i++)
		cout << " " << a[i];
} // end printArray()

void avg(int a[], int size) { //avg-case sort
	for(int i=0; i < size; i++)
		a[i] = (rand() * 1000)/17;
} // end avg()

void best(int a[], int size) { //best-case sort
	int n = 0;
	for(int i=0; i < size; i++) {
		a[i] = n;
		n++;
	}
} // end best()

void worst(int a[], int size) { //worst-case sort
	int n = size;
	for(int i=0; i < size; i++) {
		a[i] = n;
		--n;
	}
} // end worst()

int main() {
	int size = 64;
	int* array = new int[size];
	srand(time(0));

	avg(array, size-1);
	cout << "Check if avg-case array is sorted." << endl;
	isSorted(array, size-1);

	clock_t time = clock();
	quickSort(array, 0, size-1);
	time = clock()-time;
	cout << "Average-case quickSort() took: "
		 << (int)time/(CLOCKS_PER_SEC/1000) << "ms\n"  << endl;
	isSorted(array, size-1);

/*	worst(array, size);
	cout << "Check if worst-case array is sorted." << endl;
	isSorted(array, size-1);

	time = clock();
	quickSort(array, 0, size-1);
	time = clock()-time;
	cout << "Worst-case quickSort() took: "
		 << (int)time/(CLOCKS_PER_SEC/1000) << "ms\n"  << endl;

	best(array, size);
	cout << "Check if best-case is sorted." << endl;
	isSorted(array, size-1);

	time = clock();
	quickSort(array, 0, size-1);
	time = clock()-time;
	cout << "Best-case quickSort() took: "
		 << (int)time/(CLOCKS_PER_SEC/1000) << "ms\n"  << endl;*/

	return 0;
}