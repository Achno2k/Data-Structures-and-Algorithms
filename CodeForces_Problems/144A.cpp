#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int max_h = *std::max_element(arr.begin(), arr.end());
	int min_h = *std::min_element(arr.begin(), arr.end());

	int maxIdx = -1;
	int minIdx = -1;

	for(int i=0; i<n; i++){
		if(max_h == arr[i])
			maxIdx = i;
	}

	for(int i=n-1; i>=0; i--){
		if(min_h = arr[i])
			minIdx = i;
	}

	int swap1 = maxIdx;
	int swap2 = n-2-minIdx;

	if(minIdx < maxIdx)
		swap2--;


	cout << swap1 + swap2 << endl;

	return 0;
}