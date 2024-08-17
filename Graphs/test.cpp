#include <bits/stdc++.h>
using namespace std;

bool is_prime (int n) {
	if (n <= 1) return false;
	for (int i=2; i<=n/2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int solve (int N) {
	vector<int> primeNums; 
	for(int i=2; i<=100; i++) {
		if (is_prime(i)) {
			primeNums.push_back(i);
		}
	}

	int total = primeNums.size()  * primeNums.size();
	int invalid = 0;

	unordered_set<int> primes(primeNums.begin(), primeNums.end());

	for (int i: primeNums) {
		for (int j: primeNums) {
			if (primes.find(i + j) != primes.end()) {
				invalid ++;
			}
		}
	}
	return total-invalid;
}

int main() {
	int N;
	cin >> N;

	cout << solve(N) << endl;
	return 0;
}