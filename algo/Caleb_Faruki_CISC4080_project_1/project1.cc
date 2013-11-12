#include "Stock.h"
//

void swap(Stock& x, Stock& y) {
	Stock temp = x; // create temp copy of x
	x = y; // overwrite original x
	y = temp; // copy temp into y
} // end swap()

/***************************SELECTION SORT****************************/

void selectSort(Stock array[], int n) {
/*Invariant: array[last+1..n-1] is sorted and
  array[last+1..n-1] > [array[0..last] */
	for(int last = n-1; last >= 1; --last) { // start from end backward
		int largest = indexOfLargest(array,last+1); // get largest elem
		swap(array[largest], array[last]); // switch largest with last elem
	}
} // end selectSort()

int indexOfLargest(const Stock array[], int size) {
	int indexSoFar = 0; //starts at 0

	for(int currIndex = 1; currIndex < size; ++currIndex) {
		if(array[currIndex] > array[indexSoFar])
			indexSoFar = currIndex;	// edit indexSoFar if bigger elem found
	}
	return indexSoFar;
} //end indexOfLargest()

/*****************************BUBBLE SORT*****************************/

void bubbleSort(Stock array[], int n) {
	//Precondition: array is an array of n items.
	//Postcondtion: array is sorted into ascending order; n is unchanged.
	bool sorted = false;

	for(int pass=1;(pass < n) && !sorted; ++pass)
		sorted = true; //assume sorted
		for(int index = 0; index < n-pass; ++index) {
			int nextIndex = index+1;
			if(array[index] > array[nextIndex]) {
				swap(array[index], array[nextIndex]);
				sorted false;
			}
		}
} // bubbleSort()

/***************************INSERTION SORT****************************/

void insertSort(Stock array[], int n) {
	for(int unsorted; unsorted < n; ++unsorted) {
		Stock nextItem = array[unsorted];
		int loc = unsorted;

		for(; (loc > 0)&&(array[loc-1] > nextItem); --loc)
			array[loc] = array[loc-1];

		array[loc] = nextItem; 
	}
} // end insertSort()

/*****************************MERGE SORT******************************/

const int MAX_SIZE = 10;

void merge(Stock array[], int first, int mid, int last) {

	Stock tmpArray[MAX_SIZE];

	int first1 = beginning;	//first of 1st subarray
	int last1 = mid;		//end of 1st subarray
	int first2 = mid + 1;	//beginning of 2nd subarray
	int last2 = last;		//end of 2nd subarray

	int index = first1;	//next available loc in tmpArray

	for(; (first1 <= last1 )&&( first2 <= last2); ++index) {
		if(array[first1] < array[first2]) {
			tmpArray[index] = array[first1];
			++first1;
		}
		else {
			tmpArray[index] = array[first2];
			++first2;
		}
	}

	for(; first1 <= last1; ++first1, ++index)
		tmpArray[index] = array[first1];

	for(; first2 <= last2; ++first2, ++index)
		tmpArray[index] = array[first2];

	for(index = first; index <= last; ++index)
		array[index] = tmpArray[index];
} // end merge()

void mergeSort(Stock array[], int n) {

	if(first < last) {
		int mid = (first + last)/2; // find midpoint index
		mergeSort(array, first, mid);
		mergeSort(array, mid+1, last);

		merge(array, first, mid, last);
	}
} // end mergeSort()

/*****************************QUICK SORT******************************/

void partition(Stock array[], int lo, int hi, int& pivotIndex) {

	//choose midpoint as pivot
	int mid = ((hi-lo)/2);

	Stock pivot = array[mid];

	int lastS1 = lo;
	int firstUnknwn = lo + 1;

	for(; firstUnknwn <= hi; ++firstUnknwn) {
		if(array[firstUnknwn] < pivotIndex) {
			++lastS1;
			swap(array[firstUnknwn], array[lastS1]);
		}
	}
	//place pivot index in proper pos and mark its loc.
	swap(array[lo], array[lastS1]);

	pivotIndex = lastS1;
} // partition()

void quickSort(Stock array[], int lo, int hi) {

	int pivotIndex; // initialize in scope.

	if(lo < hi) {
		partition(array, lo, hi, pivotIndex);//split in half

		quickSort(array, lo, pivotIndex-1); //sort 1st half
		quickSort(array, pivotIndex+1, hi); //sort 2nd half
	}
} // end quickSort()