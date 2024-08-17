#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int min_height = INT32_MAX;
	pair<int, int> ans;

	for(int i=0; i<n; i++){
		int curr_height = abs(arr[i] - arr[(i+1)%n]);

		if(min_height > curr_height){
			min_height = curr_height;
			ans = make_pair(i, (i+1) % n);
		}
	}

	cout << ans.first + 1 << " " << ans.second + 1 << endl;
}

int main()
{
	solve();
	return 0;
}