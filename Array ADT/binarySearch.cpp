#include <iostream>
using namespace std;

//using bubble sort
void sort(int *arr, int size){
	int ch;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[j]<arr[i]){
				swap(arr[i],arr[j]);
			}
		}
	}
}
//func for Binary Search
int binarySearch(int *arr, int size, int key){
	int low=0, high=size;

	for(int i=0; i<size; i++){
		int mid=(low+high)/2;
		if(key==arr[mid])
			return mid;
		else if(key>arr[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

//func for binary search using recursion
int R_binarySearch(int *arr, int key, int low, int high){
	while(low<=high){
		int mid=(low+high)/2;
		if(key==arr[mid])
			return mid;
		else if(key<arr[mid])
			return R_binarySearch(arr, key, low, (mid-1));
		else
			return R_binarySearch(arr, key, (mid+1), high);
	}
	return -1;
}




int main()
{
	int n, key;
	cout << "Enter size of array: ";
	cin>>n;

	int array[n];
	cout << "Enter the array elements: ";
	for(int i=0; i<n; i++){
		cin >> array[i];
	}
	cout << "Enter element to search: ";
	cin>>key;

	sort(array, n);
	cout << "Element found on index: " << binarySearch(array, n, key) << endl;
	cout << "Element found on index: " << R_binarySearch(array, key, 0, n) << endl;

	return 0;
}