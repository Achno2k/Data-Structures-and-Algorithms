#include <iostream>
using namespace std;

//Quick Sort or Selection Exchange Sort or Partition Exchange Sort function --> works recursively
//Time Complexity : O(n^2)
//Best case --> O(nlogn) --> partitioning is happening in the middle
//Worst case (List is already sorted) --> O(n^2) --> partitioning is happening at the end
//Average case --> O(nlogn)

int partition(int *a, int l, int h){
	int pivot = a[l];
	int i=l, j=h;

	do{
		do{i++;} while(a[i] <= pivot);
		do{j--;} while(a[j] > pivot);

		if(i<j) swap(a[i], a[j]);
	} while(i<j);

	swap(a[l], a[j]);
	return j;
}

void quickSort(int* a, int l, int h){
	int j;
	if(l<h){
		j = partition(a, l, h);
		quickSort(a, l, j);
		quickSort(a, j+1, h);
	}
}

void print(int *a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
}

int main(){

	int A[] = {4, 1, 3, 9, 7};
	quickSort(A, 0, sizeof(A)/sizeof(A[0]));
	cout << "Sorted array: ";
	print(A, sizeof(A)/sizeof(A[0]));

	return 0;
}
