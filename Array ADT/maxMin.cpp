#include <iostream>
using namespace std;


int main()
{
	int n;
	cout << "Enter size of array: ";\
	cin >> n;
	int *arr=new int[n];
	cout << "Enter elements of the array: ";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int max{arr[0]}, min{arr[0]};
	for(int i=0; i<n; i++){
		if(max<arr[i])
			max = arr[i];
		else if(min>arr[i])
			min = arr[i];
	}
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;

	return 0;
}