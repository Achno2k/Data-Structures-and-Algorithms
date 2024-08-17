#include <bits/stdc++.h>
using namespace std;

void insert(int index, int x, int size, int *arr){
	int i;
	if(index>=0 && index<=size){
		for(i=size; i>index; i--){
			arr[i] = arr[i-1];
		}
		arr[index] = x;
		size++;
	}else{
		cout << "Enter a valid Index" << endl;
	}	
}

void del(int index, int size, int *arr){
	int i;
	for(i=index; i<size; i++){
		arr[i]=arr[i+1];
	}
	size--;
}

int main()
{
	int array[5] = {2,3,4,5,6};
	insert(4,15,5,array);
	for(int i=0; i<sizeof(array)/sizeof(int); i++){
		cout << array[i] << " ";
	}
	cout << endl;

	del(4,5,array);
	for(int i=0; i<sizeof(array)/sizeof(int); i++){
		cout << array[i] << " ";
	}

	return 0;
}