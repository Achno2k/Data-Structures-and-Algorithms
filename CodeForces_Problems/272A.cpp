#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;

	int totalFingers = 0;
	for(int i=0; i<n; i++){
		int fingers;
		cin >> fingers;
		totalFingers += fingers;
	}

	int ways = 0;
    for (int i = 1; i <= 5; i++) {
        if ((totalFingers + i - 1) % (n + 1) != 1) {
            ways++;
        }
    }

    cout << ways << endl;

}


int main()
{
	solve();
	return 0;
}
