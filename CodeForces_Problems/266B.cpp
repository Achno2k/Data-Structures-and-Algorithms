#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;

	while(t > 0){
		for(int i=0; i<s.length(); i++){
			if(s[i]=='B' && s[i+1]=='G'){
				swap(s[i], s[i+1]);
				i++;
			}
		}
		t--;	
	}
	cout << s;
}

int main()
{
	solve();
	return 0;
}