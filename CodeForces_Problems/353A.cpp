#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int upper[n];
	int lower[n];

	for(int i=0; i<n; i++){
		cin >> upper[i];
		cin >> lower[i];
	}
	int upperOdd = 0;
	int lowerOdd = 0;

	for(int i=0; i<n; i++){
		if(upper[i] % 2 != 0)
			upperOdd++;
		if(lower[i] % 2 != 0)
			lowerOdd++;
	}

	if((upperOdd + lowerOdd) % 2 == 0){
		cout << (upperOdd + lowerOdd) / 2 << endl;
	}
	else
		cout << -1 << endl;

}

int main(){
	solve();
	return 0;
}