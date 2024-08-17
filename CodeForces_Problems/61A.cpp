#include <bits/stdc++.h>
using namespace std;

void solve(){
	string n, m;
	cin >> n;
	cin >> m;

	string ans= "";
	for(int i = 0; i < n.length(); i++){
		if(n[i] != m[i]){
			ans += '1';
		}
		else{
			ans += '0';
		}
	}
	cout << ans << endl;
}

int main()
{
	solve();
	return 0;
}