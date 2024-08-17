#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;

	unordered_map<char, int> mapping;
	for(auto ch : s){
		mapping[ch]++;
	}

	int count = 0;
	for(auto i : mapping){
		if(i.second > 0)
			count++;
	}
	
	if(count % 2 == 0)
		cout << "CHAT WITH HER!" << endl;
	else
		cout << "IGNORE HIM!" << endl;
}

int main()
{
	solve();
	return 0;
}