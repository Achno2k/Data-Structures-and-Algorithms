#include<bits/stdc++.h>
using namespace std;

vector<int> nsr(vector<int>& arr) {
	vector<int> answer;
	stack<int> stk;
	int n = arr.size();

	for (int i=n-1; i>=0; i--) {
		while (!stk.empty() && arr[stk.top()] >= arr[i])
			stk.pop();
		if (stk.empty())
			answer.push_back(n);
		else
			answer.push_back(stk.top());

		stk.push(i);
	}
	reverse(answer.begin(), answer.end());

	return answer;
}

vector<int> nsl(vector<int>& arr) {
	vector<int> answer;
	stack<int> stk;
	int n = arr.size();

	for (int i=0; i<n; i++) {
		while (!stk.empty() && arr[stk.top()] >= arr[i])
			stk.pop();
		if (stk.empty())
			answer.push_back(-1);
		else
			answer.push_back(stk.top());

		stk.push(i);
	}
	return answer;
}

int maxHistogramArea(vector<int>& height) {
	int maxArea = INT_MIN;
	int n = height.size();

	vector<int> nsrArr = nsr(height);
	vector<int> nslArr = nsl(height);
	for (int i=0; i<n; i++) {
		int len = nsrArr[i] - nslArr[i] - 1;
		int currArea = len * height[i];
		maxArea = max(maxArea, currArea); 
	}

	return maxArea;
}

int maxRectArea(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> height(n, 0);
	int maxArea = INT_MIN;

	for (int i=0; i<n; i++) {
		int currArea;
		for(int j=0; j<m; j++) {
			if (matrix[i][j] == 0){
				height[j] = 0;
			} 
			else{
				height[j] =  height[j] + matrix[i][j];
			}
		}
		currArea = maxHistogramArea(height);
		maxArea = max(maxArea, currArea);
	}
	return maxArea;
}

int main() {
	vector<vector<int>> matrix = {{0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0}};
	int maxArea = maxRectArea(matrix);
	cout << "Max Area of Rectangle is: " << maxArea << endl;

	return 0;
}