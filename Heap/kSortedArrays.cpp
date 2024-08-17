#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& arr, int k) {
	vector<int> temp;

	int n = arr.size();
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i=0; i<n; i++) {
		minHeap.push(arr[i]);
		if (minHeap.size() > k) {
			temp.push_back(minHeap.top());;
			minHeap.pop();
		}
	}
	while (minHeap.size()) {
		temp.push_back(minHeap.top());
		minHeap.pop();
	}

	return temp;
}

int main() {
	vector<int> arr = {6,5,3,2,8,10,9};
	int k;
	cin >> k;
	vector<int> sortedArr = solve(arr, k);
	for (auto i: sortedArr) {
		cout << i << " ";
	}
	return 0;
}