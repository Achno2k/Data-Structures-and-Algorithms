#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    int arr[7];
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    int idx = 0;
    while (n > 0) {
        n -= arr[idx];
        if (n <= 0) {
            break;
        }
        idx = (idx + 1) % 7;
    }

    cout << idx + 1 << endl;
}

int main() {
    solve();
    return 0;
}
