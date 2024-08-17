#include <bits/stdc++.h>
using namespace std;

int func(vector<int>& coins, int m) {
	int n = coins.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for (int i=0; i<n+1; i++) {
		dp[i][0] = 1;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (coins[i-1] <= j) {
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][m];
}

int main() {
	std::vector<int> coins = {1, 2, 3};
	int m = 4;
	cout << func(coins, m) << endl;
	return 0;
}