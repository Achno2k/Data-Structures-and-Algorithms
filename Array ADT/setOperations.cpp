#include <iostream>
using namespace std;

int* Union(int *arr1, int *arr2, int m, int n){
	int *arr3;
	arr3=new int[m+n];
	int i{0},j{0},k{0};
		
	while(i<m && j<n){
		if(arr1[i]<arr2[j])
			arr3[k++] = arr1[i++];
		else if(arr2[j]<arr1[i])
			arr3[k++] = arr2[j++];
		else{
			arr3[k++] = arr1[i++];
			j++;
		}
	}
	for(;i<m;i++) 						
		arr3[k++] = arr1[i++];					
	for(;j<n;j++)
		arr3[k++] = arr2[j++];

	return arr3;
	delete[] arr3;
}

int* Intersection(int *arr1, int *arr2, int m, int n){
	int *arr3;
	arr3=new int[m+n];
	int i{0},j{0},k{0};
		
	while(i<m && j<n){
		if(arr1[i]<arr2[j])
			i++;
		else if(arr2[j]<arr1[i])
			j++;
		else{
			arr3[k++] = arr1[i++];
			j++;
		}
	} 
	
	return arr3;
	delete[] arr3;
}

int* Difference(int *arr1, int *arr2, int m, int n){
	int *arr3;
	arr3=new int[m+n];
	int i{0},j{0},k{0};
		
	while(i<m && j<n){
		if(arr1[i]<arr2[j])
			arr3[k++] = arr1[i++];
		else if(arr2[j]<arr1[i])
			j++;
		else{
			i++;
			j++;
		}
	}
	for(;i<m;i++) 								
		arr3[k++] = arr1[i++];	

	return arr3;
	delete[] arr3;
}

void display(int *arr, int len){
	for(int i=0; i<len; i++){
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr1[5]={2,7,14,19,23};
	int arr2[5]={3,7,12,19,69};

	int *arr3 = Union(arr1, arr2, 5, 5);
	//int *arr3 = Intersection(arr1, arr2, 5, 5);
	//int *arr3 = Difference(arr1, arr2, 5, 5);

	display(arr3, 10);
}