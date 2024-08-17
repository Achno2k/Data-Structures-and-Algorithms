#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int max_points = arr[0];
	int min_points = arr[0];
	int count = 0;

	for(int i=1; i<n; i++){
		if(arr[i] > max_points){
			max_points = arr[i];
			count++;
		}
		if(arr[i] < min_points){
			min_points = arr[i];
			count++;
		}
	}
	cout << count << endl;
}

int main()
{
	solve();
	return 0;
}