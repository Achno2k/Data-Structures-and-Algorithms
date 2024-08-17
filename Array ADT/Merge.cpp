#include <iostream>
using namespace std;

int* merge(int *arr1, int *arr2, int m, int n){
	int *arr3;
	arr3=new int[m+n];
	int i{0},j{0},k{0};
		
	while(i<m && j<n){
		if(arr1[i]<arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}
	for(;i<m;i++) 								//here adding all the remaining elements that
		arr3[k++] = arr1[i++];					//that are left in both the arrays after the comparision
	for(;j<n;j++)
		arr3[k++] = arr2[j++];

	return arr3;
	delete[] arr3;
}

int main()
{
	int arr1[5]={2,6,14,19,23};
	int arr2[5]={3,7,12,54,69};
	int *arr3 = merge(arr1, arr2, 5, 5);

	for(int i=0; i<10-1; i++) //ending val should be (m+n)-1, otherwise it takes one extra space
		cout << arr3[i] << " ";

	return 0;

}