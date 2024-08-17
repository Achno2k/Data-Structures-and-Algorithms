#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n; 
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	vector<string> result;
	for(int i = 0; i < n; i++){
		int count = arr[i].length();
		if(count > 10){
			string ans = "";
			ans = arr[i][0] + to_string(count - 2) + arr[i][count - 1];
			result.push_back(ans);
		}
		else {
			result.push_back(arr[i]);
		}
	}

	for(auto i : result){
		cout << i << endl;
	}
}

int main() {
	solve();
	return 0;
}
