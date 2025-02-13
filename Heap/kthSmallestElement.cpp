#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int k) {
	int n = arr.size();
	priority_queue<int> maxHeap;

	for (int i=0; i<n; i++) {
		maxHeap.push(arr[i]);
		if (maxHeap.size() > k)
			maxHeap.pop();
	}
	return maxHeap.top();
}

int main() {
	vector<int> arr = {7,10,4,3,20,15};
	int k;
	cin >> k;
	cout << "Kth Smallest Element is: " << solve(arr, k) << endl;

	return 0;
}