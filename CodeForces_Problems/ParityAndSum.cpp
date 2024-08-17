#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);

    int even_count = 0, odd_count = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
    }

    int ans = min(even_count, odd_count);
    cout << ans << '\n';
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
