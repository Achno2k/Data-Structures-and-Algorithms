#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr, int k, int x) {
	int n = arr.size();
	priority_queue<pair<int,int>> maxHeap;
	vector<int> temp;
	for (int i=0; i<n; i++) {
		maxHeap.push({abs(arr[i] - x), arr[i]});
		if (maxHeap.size() > k) {
			maxHeap.pop();
		}
	}
	while (maxHeap.size()) {
		temp.push_back(maxHeap.top().second);
		maxHeap.pop();
	}
	return temp;
}


int main() {
	vector<int> arr = {5,6,7,8,9};
	int k = 3;
	int x = 7;

	vector<int> ans = solve(arr, k, x);
	for (int i: ans) {
		cout  << i << " ";
	}

	return 0;
}