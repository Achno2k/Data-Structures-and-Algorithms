#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	string t;

	cin >> s >> t;

	string reverse = "";
	int i = t.length() - 1;
	while(i >= 0){
		reverse += t[i];
		i--;
	}

	if(s == reverse){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

}

int main()
{
	solve();
	return 0;
}