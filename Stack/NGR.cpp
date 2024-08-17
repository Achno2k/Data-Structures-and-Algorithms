#include <bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterRight(vector<int>& vec) {
	vector<int> answer;
	stack<int> stk;

	int n = vec.size();
	for (int i=n-1; i>=0; i--) {
		while(!stk.empty() && vec[i] >= stk.top()) {
			stk.pop();
		}

		if (stk.empty())
			answer.push_back(-1);
		else 
			answer.push_back(stk.top());

		stk.push(vec[i]);
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main() {
	vector<int> vec = {1,3,2,4};
	vector<int> answer = nearestGreaterRight(vec);
	for (auto i: answer)
		cout << i << " ";

	return 0;
}