#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int p1, p2, p3;
    int sure_count = 0; 

    for (int i = 0; i < n; ++i) {
        cin >> p1 >> p2 >> p3;
        if (p1 + p2 + p3 >= 2) {
            sure_count++;
        }
    }

    cout << sure_count << endl;
}

int main()
{
	solve();
	return 0;
}