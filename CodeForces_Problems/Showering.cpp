#include <bits/stdc++.h> 
using namespace std;
#define ll long long

void solve() {
    ll n, s, m;
    cin >> n >> s >> m;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        tasks[i] = {l, r}; 
    }
    
    if (tasks[0].first >= s) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (tasks[i].first - tasks[i-1].second >= s) {
            cout << "YES" << endl;
            return;
        }
    }

    if (m - tasks[n-1].second >= s) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
