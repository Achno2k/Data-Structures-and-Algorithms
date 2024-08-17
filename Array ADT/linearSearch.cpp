//we can improve the time complexity 
//of linear search by the following 2 methods


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(int *arr, int len){
	for(int i=0; i<len; i++){
		cout << arr[i] << " ";
	}
}

//using transposition
int Tsearch(int *arr, int len, int key){
	int i;
	for(i=0; i<len; i++){
		if(arr[i]==key){
			swap(arr[i], arr[i-1]);
			return i-1;
		}
		return -1;
	}
}


//using Move to front method
int Msearch(int *arr, int len, int key){
	int i;
	for(i=0; i<len; i++){
		if(arr[i]==key){
			swap(arr[i], arr[0]);
			return 0;
		}
		return -1;
	}
}

int main()
{
	int array[5] = {1,2,3,4,5};
	cout << "Index: " << Tsearch(array, 5, 4) << endl;
	display(array, 5);
	cout << "Index: " << Msearch(array, 5, 4) << endl;
	display(array, 5);
	return 0;
}