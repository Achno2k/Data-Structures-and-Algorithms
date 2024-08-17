#include <iostream>
using namespace std;

void reverse(int *arr, int n){
	int *b=new int[n];
	for(int i=n-1,j=0; i>=0; i--,j++){
		b[j]=arr[i];
	}
	for(int i=0; i<5; i++){
		arr[i]=b[i];
	}
	delete[] b;
}

void reverse2(int *arr, int n){
	for(int i=0,j=n-1; i<j; i++,j--){
		swap(arr[i],arr[j]);
	}
}

void display(int *arr, int len){
	for(int i=0; i<len; i++){
		cout << arr[i] << " ";
	}
}

int main()
{
	int a[5]={1,2,3,4,5};
	//reverse(a,5);
	reverse2(a,5);
	display(a,5);
	
	return 0;
}