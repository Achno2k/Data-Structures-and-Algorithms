#include <bits/stdc++.h> 
using namespace std;
#define ll long long

void solve () {
	ll n;
	cin >> n;

	int tens = n % 10;
	int unit = n / 10;
	cout << tens + unit << endl;
}

int main () {
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}