#include <iostream>
using namespace std;

//Insertion Sort
//Time Complexity : O(n^2)

void insertionSort(int *a, int n){
	int j, x;
	for(int i=1; i<n; i++){
		j = i-1;
		x = a[i];
		while(j >= 0 && a[j] > x){
			a[j+1] = a[j];
			 j--;
		}
		a[j+1] = x;
	}
}

void print(int *a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
}

int main(){

	int A[] = {8, 5, 7, 3, 2};
	insertionSort(A, sizeof(A)/sizeof(A[0]));
	print(A, sizeof(A)/sizeof(A[0]));

	return 0;
}