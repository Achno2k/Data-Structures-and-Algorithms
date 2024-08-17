#include <iostream>
using namespace std;

int findMax(int A[], int n){
	int max = A[0];
	for(int i=0; i<n; i++){
		if(max < A[i])
			max = A[i];
	}
	return max;
}


//Count Sort Algorithm
//Time complexity --> O(n)
//But it takes a lot of space

void countSort(int A[], int n){
	int m = findMax(A, n)+1;
	int *count = new int[m]{0};
	
	for(int i=0; i<n; i++)
		count[A[i]]++;

	int index = 0;
	for(int i=0; i<m; i++){
		if(count[i] > 0){
			do{
				A[index++] = i;
				count[i]--;
			}while(count[i] > 0);
		}	
	}
	delete[] count;
}

void print(int A[], int n){
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
}


int main()
{
	int A[] = {8, 5, 7, 3, 2};
	countSort(A, sizeof(A)/sizeof(A[0]));
	cout << "Sorted array: ";
	print(A, sizeof(A)/sizeof(A[0]));

	return 0;
}