#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	unordered_map<int, int> mapping;
	for(int i=0; i<n; i++){
		mapping[arr[i]] = i;
	}

	int m;
	cin >> m;
	ll left = 0, right = 0;
	for(int i=0; i<m; i++){
		int target;
		cin >> target;

		left += mapping[target] + 1;
		right += n - mapping[target];
	}

	cout << left << " " << right << endl;
}

int main()
{
	solve();
	return 0;
}