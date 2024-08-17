#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;

	int count = 0;
	for(int a = 0; a <= sqrt(n); a++){
		int b = n - a * a;
		if(a + b * b == m){
			count ++;
		}
	}
	cout << count << endl;
}

int main()
{
	solve();
	return 0;
}