#include <bits/stdc++.h>
using namespace std;

int func (string& a, string& b, int n, int m) {
	int dp[n+1][m+1];
	int len = 0;

	for (int i=0; i<n+1; i++) {
		for (int j=0; j<m+1; j++) {
			if (i==0 || j==0) 
				dp[i][j] = 0;
			else if (a[i-1] == b[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
				len = max(len, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	} 
	return len;
}

int main () {
	string a = "abcdef";
	string b = "abxgey";
	
	int n = a.size();
	int m = b.size();

	cout << func (a, b, n, m) << endl;

	return 0;
}