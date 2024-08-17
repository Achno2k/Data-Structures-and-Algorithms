//Nearest Greater to Left
#include <bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterLeft(vector<int>& arr){
	int n = arr.size();
	
	stack<int> stk;
	vector<int> answer;
	for (int i=0; i<n; i++) {
		while (!stk.empty() && stk.top() <= arr[i])
			stk.pop();

		if(stk.empty())
			answer.push_back(-1);
		else
			answer.push_back(stk.top());

		stk.push(arr[i]);
	}
	return answer;
}

int main() {
	vector<int> vec = {1, 3, 2, 4};			
	vector<int> answer = nearestGreaterLeft(vec);		// OUTPUT = {-1, -1, 3, -1}
	for (auto i: answer) {
		cout << i << " ";
	}

	return 0;
}