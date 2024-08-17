#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n, k;
	cin >> n >> k;

	long long oddCount = (n+1)/2;
	long long evenCount = n/2;

	if(k <= oddCount)
		cout << 2 * k - 1 << endl;
	else
		cout << 2 * (k - oddCount) << endl;
}

int main()
{
	solve();
	return 0;
}