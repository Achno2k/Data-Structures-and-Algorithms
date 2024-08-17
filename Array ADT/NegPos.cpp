#include <iostream>
using namespace std;

void shiftElements(int *arr, int len){
	int i=0, j=len-1;
	while(i<j){
		while(arr[i]<0){
			i++;
		}
		while(arr[j]>=0){
			j--;
		}
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}
}

void display(int *arr, int len){
	for(int i=0; i<len; i++){
		cout << arr[i] << " ";
	}
}

int main()
{
	int array[10]={-2,7,8,-9,6,-11,4,7,-1,3};
	display(array,10);
	cout << endl;
	shiftElements(array,10);
	display(array,10);

	return 0;
}