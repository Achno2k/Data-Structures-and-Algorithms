#include <bits/stdc++.h>
using namespace std;

vector<int> findLeftMax(vector<int>& arr) {
	int n = arr.size();
	vector<int> leftMax(n, 0);
	leftMax[0] = arr[0];

	for (int i=1; i<n; i++) {
		leftMax[i] = max(leftMax[i-1], arr[i]);
	}
	return leftMax;
}

vector<int> findRightMax(vector<int>& arr){
	int n = arr.size();
	vector<int> rightMax(n, 0);
	rightMax[n-1] = arr[n-1];

	for (int i=n-1; i>0; i--) {
		rightMax[i-1] = max(rightMax[i], arr[i-1]);
	}
	return rightMax;
}


int rainwaterArea(vector<int>& height) {
	int totalArea = 0;
	int n = height.size();
	vector<int> leftMax = findLeftMax(height);
	vector<int> rightMax = findRightMax(height);

	for (int i=0; i<n; i++) {
		int currArea;
		currArea = min(leftMax[i], rightMax[i]) - height[i];

		totalArea += currArea;
	}
	return totalArea;
}

int main() {
	vector<int> height = {3,0,0,2,0,4};
	cout << "Maximum Rainwater Area: " << rainwaterArea(height);
	return 0;
}