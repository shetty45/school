#include "Array.h"

using namespace std;

Array::Array() {
	size = DEFSIZE;
	arr = new int[size];

	for(int i=0; i<size; i++)
		arr[i] = DEFVAL;
}

Array::Array(int a) {
	if(a < 1)
		size = DEFSIZE;
	else if (a > MAXSIZE)
		size = MAXSIZE;
	else
		size = a;

	arr = new int[size];
	for(int i; i<size; i++)
		arr[i] = DEFVAL;
}

Array::~Array() {
	for(int i; i<size; i++) {
		delete arr;
		arr = NULL;
	}
}

void Array::quickSort(const Array & a, int lo, int hi) {
	int pivotIndex; //initialize in scope
	if(lo < hi) {
		partition(a, lo, hi, pivotIndex); //split in half
		quickSort(a, lo, pivotIndex-1); //sort 1st half
		quickSort(a, pivotIndex+1, hi); //sort 2nd half
	}
}

int Array::partition(const Array & a, int lo, int hi, int pivotIndex) {
	//pivot at midpoint
	int mid = ((hi-lo)/2);
	int pivot = a[mid];
	int lastS1 = lo;

	for(int unknown = lo+1; unknown <= hi; ++unknown) {
		if(a[unknown] < pivotIndex) {
			++lastS1;
			swap(arr[unknown], a[lastS1]);
		}
	}
	//put pivotIndex in proper position, mark its location
	swap(a[lo], a[lastS1]);
	pivotIndex = lastS1;
}

void Array::swap(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

bool Array::isSorted(const Array & a) {
	for(int i=0; i < size-1; i++) {
		if(arr[i] > arr[i+1]) {
			cout << "Array is not sorted." << endl;
			return false;
		}
	cout << "Array is sorted." << endl;
	return true;
	}
}

void Array::best() { //best-case sort
	int n = 0;
	for(int i=0; i < size; i++) {
		arr[i] = n;
		n++;
	}
}
void Array::worst() { //worst-case sort
	int n = size;
	for(int i=0; i < size; i++) {
		arr[i] = n;
		--n;
	}
}
void Array::avg() { //avg-case sort
	for(int i; i < size; i++)
		arr[i] = (rand() * 1000)/17;
}

void Array::printArray() {
	for(int i=0; i < size; i++)
		cout << " " << arr[i];
}
