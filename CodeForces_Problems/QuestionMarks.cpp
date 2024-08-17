#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve() {
	int n;
	string s;
	cin >> n;
	cin >> s;

	unordered_map<char, int> mp;
	int ans = 0;

	for (char& ch: s) {
		if (ch != '?') {
			mp[ch] ++;
		}
	}

	ans += min(mp['A'], n);
	ans += min(mp['B'], n);
	ans += min(mp['C'], n);
	ans += min(mp['D'], n);

	cout << ans << '\n'; 
}

int main() {
	ll t;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}