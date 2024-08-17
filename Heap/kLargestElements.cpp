#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i=0; i<arr.size(); i++) {
		minHeap.push(arr[i]);
		if (minHeap.size() > k) {
			minHeap.pop();
		}
	}

	while (minHeap.size()) {
		cout << minHeap.top() << endl;
		minHeap.pop();
	}
}

int main() {
	vector<int> arr = {7,10,4,3,20,15};
	int k;
	cin >> k;
	solve(arr, k);
	return 0;
}