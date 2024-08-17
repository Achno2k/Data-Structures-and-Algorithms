#include <iostream>
using namespace std;

int Max(int *arr, int len){
	int temp=arr[0];
	for(int i=0; i<len; i++){
		if(temp<arr[i]){
			temp = arr[i];
		}
	}
	return temp;
}
int Min(int *arr, int len){
	int temp=arr[0];
	for(int i=0; i<len; i++){
		if(temp>arr[i]){
			temp = arr[i];
		}
	}
	return temp;
}

int main()
{
	int n;
	cout << "Enter size of the array: ";
	cin >> n;

	cout << "Enter elements of the array: ";
	int *a=new int[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	int max=Max(a,n);
	int min=Min(a,n);

	int *h;
	h=new int[max]{0};
	for(int i=0; i<n; i++){
		h[a[i]]++;
	}
	cout << "Duplate Elements are: ";
	for(int i=min; i<max; i++){
		if(h[i]>0)
			cout << i << " -> " << h[i] << " times" << endl;
	}

	delete[] a, h;
	return 0;
}