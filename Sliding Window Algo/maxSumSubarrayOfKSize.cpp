#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int k) {
	int n = arr.size();
	int i = 0, j = 0;

	int mx = 0;
	int sum = 0;
	while (j < n) {
		sum += arr[j];
		if (j-i+1 < k) {
			j++;
		} else if (j-i+1 == k) {
			mx = max(mx, sum);
			sum -= arr[i];
			j++;
			i++;
		}
	}
	return mx;
}

int main() {
	vector<int> arr = {100,200,300,400};
	int k;
	cin >> k;
	cout << solve(arr, k) << endl;
	return 0;
}