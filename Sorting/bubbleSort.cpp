#include <iostream>
using namespace std;

//Bubble Sort
//Time Complexity : O(n^2)

void bubbleSort(int *a, int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

void print(int *a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
}

int main()
{
	int A[] = {8, 5, 7, 3, 2};
	bubbleSort(A, sizeof(A)/sizeof(A[0]));
	cout << "Sorted array: ";
	print(A, sizeof(A)/sizeof(A[0]));

	return 0;
}