#include <bits/stdc++.h>
using namespace std;

int func (string& a, string& b, int n, int m) {
	int dp[n+1][m+1];
	for (int i=0; i<n+1; i++) {
		for (int j=0; j<m+1; j++) {
			if (i==0 || j==0) 
				dp[i][j] = 0;
			else if (a[i-1] == b[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	} 
	
	return (m+n-dp[n][m]);
}

int main () {
	string a = "geek";
	string b = "eke";
	
	int n = a.size();
	int m = b.size();

	cout << func (a, b, n, m) << endl;			//output = "geeke"

	return 0;
}