#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr, int k) {
	int n = arr.size();
	queue<int> q;
	vector<int> ans;
	int i=0, j=0;

	while (j < n) {
		if (arr[j] < 0) q.push(arr[j]);
		if (j-i+1 < k) j++;
		else if (j-i+1 == k) {
			if (q.empty()) {
				ans.push_back(0);
			}
			else {
				ans.push_back(q.front());
				if (arr[i] == q.front()){
					q.pop();
				} 
			}
			i++;
			j++;
		}
	}
	return ans;
}

int main() {
	vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
	int k;
	cin >> k;

	vector<int> ans = solve(arr, k);
	for (int i: ans) {
		cout << i << " ";
	}

	return 0;
}