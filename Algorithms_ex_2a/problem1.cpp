#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>


#define INF  9999;

//
using namespace std;


int createSequence(int *arr, int size);
int findMedianOfSorted(int *arr1, int *arr2, int size1, int size2);


int createSequence(int *arr, int size) {
	int firstSeqNum = rand() % 100;
	int signForSeq = rand() % 2;
	
	if (signForSeq == 1) {
		firstSeqNum = firstSeqNum * (-1);
	}
	arr[0] = firstSeqNum;

	for (int i = 1; i < size; i++) {
		arr[i] = (i+1) ;
	}
	return *arr;
}

int findMedianOfSorted(int *arr1, int *arr2, int size1, int size2) {
	int low = 0;
	int high = size1;
	int partitionA = (low + high / 2);
	int partitionB = (size1 + size2 + 1) / 2 - partitionA;
	if (size1 > size2) {
		findMedianOfSorted(arr2, arr1, size2, size1);
	}


	while (low <= high) {
		int partitionA = (low + high / 2);
		int partitionB = (size1 + size2 + 1) / 2 - partitionA;


		int maxLeftA = arr1[partitionA - 1];
		if (partitionA == 0) {   //edge case
			maxLeftA = -INF;
		}
		int minRightA = arr1[partitionA];
		if (partitionA == size1) { //edge case
			maxLeftA = INF;
		}

		int maxLeftB = arr2[partitionB - 1];
		if (partitionB == 0) { //edge case
			maxLeftB = -INF;
		}
		int minRightB = arr2[partitionB];
		if (partitionB == size2) { //edge case
			minRightB = INF;
		}
		if (maxLeftA <= minRightB && maxLeftB <= minRightA) { // we found the right partition
			if ((size1 + size2) % 2 == 0) { // if the union of both of the arrays is even
				return (fmax(maxLeftA, maxLeftB) + fmin(minRightA, minRightB)) / 2;
			}
			else {   // the union of the arrays is odd
				return fmax(maxLeftA, maxLeftB);
			}
		}
		else if (maxLeftA < minRightB) {  // move partitionA 1 step to the left
			high = partitionA - 1;
		}
		else {
			low = partitionA + 1; // move paritionA 1 step to the right
		}

	}
}


void main() {
	srand(time(NULL));
	int *arr1, *arr2;
	int size1 = 5, size2 = 7;
	int median;
	arr1 = new int[size1];
	arr2 = new int[size2];
	*arr1 = createSequence(arr1, size1);
	*arr2 = createSequence(arr2, size2);

	//int arr1[4] = { 2,3,5,8 };
	//int arr2[6] = { 10,12,14,16,18,20 };


	for (int i = 0; i < size1; i++) {
		cout << arr1[i] << ",";
	}
	cout << " END " << endl;
	for (int i = 0; i < size2; i++) {
		cout << arr2[i] << ",";
	}
	median = findMedianOfSorted(arr1, arr2, size1, size2);
	cout << " the median is :" << median << endl;
	system("pause");

}


