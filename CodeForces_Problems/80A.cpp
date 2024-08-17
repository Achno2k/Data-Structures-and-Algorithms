#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int num){
	for(int i=2; i<=num/2; i++){
		if(num % i == 0)
			return false;
	}
	return true;
}

void solve(){
	int n, m;
	cin >> n >> m;

	bool flag = true;
	int nextPrime = n + 1;
	while(flag){
		if(checkPrime(nextPrime))
			flag = false;
		else
			nextPrime++;
	}
	if(nextPrime == m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	solve();
	return 0;
}