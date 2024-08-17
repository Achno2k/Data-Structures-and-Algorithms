#include <bits/stdc++.h>
using namespace std;

void solve(){
	string str;
	cin >> str;

	string ans = "";
	for(auto ch : str){
		ch = tolower(ch);
		if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' && ch != 'y'){
			ans += '.';
			ans += ch;
		}
	}
	cout << ans;
}

int main()
{
	solve();
	return 0;
}