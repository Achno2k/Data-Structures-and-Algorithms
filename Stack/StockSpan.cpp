#include <bits/stdc++.h>
using namespace std;

//Brute Force Solution
vector<int> solve1(vector<int>& arr){
	vector<int> answer;
	int n = arr.size();

	for (int i=n-1; i>0; i--) {
		int count = 1;
		for (int j=i-1; j>=0; j--) {
			if (arr[i] < arr[j])
				break;
			count++;
		}
		answer.push_back(count);
	}
	answer.push_back(1);
	reverse(answer.begin(), answer.end());
	return answer;
}


//Using Stack
vector<int> solve2(vector<int>& arr){
	int n = arr.size();
	vector<int> answer;
	stack<int> stk;
	for (int i=0; i<n; i++) {
		while (!stk.empty() && arr[stk.top()] < arr[i]) {
			stk.pop();
		}
		if (stk.empty()) {
			answer.push_back(1);
		} else {
			answer.push_back(i - stk.top());
		}

		stk.push(i);
	}
	return answer;
}
int main(){
	vector<int> vec = {100, 80, 60, 70, 60, 75, 85};
	vector<int> answer1 = solve1(vec);
	vector<int> answer2 = solve2(vec);
	for (int i: answer1) {
		cout << i << " ";
	}
	cout << endl;
	for (int i: answer2) {
		cout << i << " ";
	}

	return 0;
}