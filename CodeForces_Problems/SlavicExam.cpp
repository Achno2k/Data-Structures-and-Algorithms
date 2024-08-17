#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();
    
    int j = 0;
    
    for (int i = 0; i < n; i++) {
        if (j < m && (s[i] == t[j] || s[i] == '?')) {
            s[i] = t[j]; 
            j++;
        } else if (s[i] == '?') {
            s[i] = 'a';
        }
    }

    if (j == m) {
        cout << "YES" << '\n';
        cout << s << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
