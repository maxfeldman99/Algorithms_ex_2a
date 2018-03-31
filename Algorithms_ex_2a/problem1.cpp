#include <iostream>
#include <ctime>
#include <cstdlib>

//
using namespace std;


int createSequence(int *arr, int size);

void main() {
	srand(time(NULL));
	int *arr1, *arr2;
	int size1=5, size2=7;
	arr1 = new int[size1];
	arr2 = new int[size2];
	*arr1 = createSequence(arr1, size1);
	*arr2 = createSequence(arr2, size2);
	
	for (int i = 0; i < size1; i++) {
		cout << arr1[i] << ",";
	}
	cout << " END " << endl;
	for (int i = 0; i < size2; i++) {
		cout << arr2[i] << ",";
	}
	system("pause");

}


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




