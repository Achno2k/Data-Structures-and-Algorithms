#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;

	map<string, int> goals;
	for(int i = 0; i < n; i++){
		string team;
		cin >> team;
		goals[team] ++;
	}

	int max_goals = INT_MIN;
	string winner;
	for(auto it : goals){
		if(it.second > max_goals){
			max_goals = it.second;
			winner = it.first;
		}
	}

	cout << winner <<  endl;
}

int main()
{
	solve();
	return 0;
}