#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A, int N, int X, int Y) {
	int maxlen = 0;
	int currlen = 0;
	int type1 = X;
	int type2 = Y;

	for (int i=1; i<=N; i++) {
		if (A[i-1] == 0) {
			currlen ++;
		} else if (A[i-1] - 1 == 0) {
			type1--;
			currlen++;
		} else if (type2 > 0) {
			type2--;
			currlen++;
		} else {
			currlen = 0;
			type1 = X;
			type2 = Y;
		}
		maxlen = max(maxlen, currlen);
	}
	cout << maxlen;
	return maxlen;
}

int main () {
	int N = 6, X=4, Y=2;
	// cin >> N >> X >> Y;

	vector<int> A = {4,2,1,3,2,5};
	// for(int i=0; i<N; i++) {
	// 	cin >> A[i];
	// }

	cout << solve(A, N, X, Y) << "\n";

	return 0;
}