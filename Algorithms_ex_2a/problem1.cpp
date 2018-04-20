#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>


#define INF  9999;


using namespace std;

int findMedianOfSorted(int *arr1, int *arr2, int size1, int size2, int low, int high);
int* setArray(int size);
int define_size();
void printArray(int *arr,int size);

void printArray(int *arr, int size) {
	cout << "values of array of size " << size << " are : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ",";
	}
	cout << endl;
}

int* setArray(int size) {
	int val;
	int *arr;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "insert a value to the array " << endl;
			cin >> val;
			if (!cin) {
				cout << "wrong input , input must contain numbers only!" << endl;
				system("pause");
				exit(1);
			}
		arr[i] = val;
	}
	cout << endl;
	return arr;
}

int define_size() {
	int size;
	cout << "choose size for the array : " << endl;
	cin >> size;
	if (!cin) {
		cout << "wrong input , input must contain numbers only!" << endl;
		system("pause");
		exit(1);
	}
	cout << endl;
	return size;
}

int findMedianOfSorted(int *arr1, int *arr2, int size1, int size2, int low, int high) {


	if (size1 > size2) {
		findMedianOfSorted(arr2, arr1, size2, size1, low, high);
	}


	else {
		int partitionA = (low + high) / 2;
		int partitionB = (size1 + size2 + 1) / 2 - partitionA;


		int maxLeftA = arr1[partitionA - 1];

		int minRightA = arr1[partitionA];

		int maxLeftB = arr2[partitionB - 1];

		int minRightB = arr2[partitionB];


		if (partitionA > size1 - 1) {
			minRightA = INF;
		}
		if (partitionA == 0) {
			maxLeftA = -INF;
		}



		if (maxLeftA <= minRightB && maxLeftB <= minRightA) { // we found the right partition
			if ((size1 + size2) % 2 == 0) { // if the union of both of the arrays is even
				return fmin(fmax(maxLeftA, maxLeftB), fmin(minRightA, minRightB));
			}
			else {   // the union of the arrays is odd
				return fmax(maxLeftA, maxLeftB);
			}
		}
		else if (maxLeftB > minRightA) {  // move paritionA 1 step to the right
			findMedianOfSorted(arr1, arr2, size1, size2, partitionA + 1, high);
			
		}
		else { // move partitionA 1 step to the left
			
			findMedianOfSorted(arr1, arr2, size1, size2, low, partitionA - 1);
		}

	}
}


void main() {
	srand(time(NULL));
	int *arr1, *arr2, size1, size2;
	int median;
	size1 = define_size();
	arr1 = setArray(size1);
	size2 = define_size();
	arr2 =setArray(size2);
	printArray(arr1, size1);
	printArray(arr2, size2);
	

	median = findMedianOfSorted(arr1, arr2, size1, size2, 0, size1);
	cout << " the median is :" << median << endl;
	system("pause");

}


