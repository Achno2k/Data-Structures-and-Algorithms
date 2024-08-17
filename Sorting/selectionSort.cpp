#include <iostream>
using namespace std;

//Selection Sort function
//Time Complexity : O(n^2)

void selectionSort(int *a, int n){
	int i, j, k;
	for(int i=0; i<n; i++){
		for(j=k=i; j<n; j++){
			if(a[k] > a[j])
				k = j;
		}
		swap(a[i], a[k]);
	}
}

void print(int *a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
}

int main(){

	int A[] = {8, 5, 7, 3, 2};
	selectionSort(A, sizeof(A)/sizeof(A[0]));
	cout << "Sorted array: ";
	print(A, sizeof(A)/sizeof(A[0]));

	return 0;
}
