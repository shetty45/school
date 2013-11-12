/**********************************************************************
* Author: Caleb Faruki
* Course: CISC4080 Algorithms
* Date: September 27, 2013
* File: Binary Search Algorithm
**********************************************************************/

int binarySearch(const int, int, int, int);

int main() {}

int binarySearch(const int array[], int first, int last, int val) {

	int index; //value we are looking for
	if(first > last)
		index = -1; //value not in original array
	else {
		int mid = (first + last)/2;
		if(value == array[mid])
			index = mix; //value found at array[mid]
		else if(value < array[mid])
			index = binarySearch(array, first, mid-1, val);
		else
			index = binarySearch(array, mid+1, last, val;)
	}
	return index;
}