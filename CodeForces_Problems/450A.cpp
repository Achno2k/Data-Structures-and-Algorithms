#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> candiesNeeded(n);
    for (int i = 0; i < n; ++i) {
        cin >> candiesNeeded[i];
    }

    int lastChild = 0;
    while (n > 1) {
        int candiesToGive = min(m, candiesNeeded[lastChild]);
        candiesNeeded[lastChild] -= candiesToGive;

        if (candiesNeeded[lastChild] <= 0) {
            n--;
        }

        lastChild = (lastChild + 1) % candiesNeeded.size();
    }

    cout << lastChild + 1 << endl; // Adding 1 to convert from 0-indexed to 1-indexed

    return 0;
}
