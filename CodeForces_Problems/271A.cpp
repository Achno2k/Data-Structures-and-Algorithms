#include <bits/stdc++.h>
using namespace std;

bool isDistinct(int num){
	unordered_set<int> numSet;
	while(num > 0){
		int digit = num % 10;
		if(numSet.count(digit) > 0)
			return false;
		numSet.insert(digit);
		num /= 10;
	}
	return true;
}

void solve(){
	int y;
	cin >> y;

	y++;
	bool flag = true;
	while(flag){
		if(isDistinct(y)){
			flag = false;
			cout << y;
		}
		else
			y++;
	}
}


int main()
{
	solve();
	return 0;
}