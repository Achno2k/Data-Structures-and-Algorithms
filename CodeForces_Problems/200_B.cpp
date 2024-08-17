#include <bits/stdc++.h>
using namespace std;

double volFrac(vector<int> arr, int n){
	int sum = 0;
	for(auto i : arr)
		sum += i;
	return static_cast<double>(sum) / n;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	double fraction = volFrac(arr, n);
	cout << fraction << endl; 

	return 0;
}