#include <bits/stdc++.h>
using namespace std;

int func(int card1, int card2) {
    if (card1 > card2) return 1;   
    if (card1 < card2) return 2;   
    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int p1wins1 = 0, p2wins1 = 0;

        int result1 = func(a1, b1);
        int result2 = func(a2, b2);
        if (result1 == 1) p1wins1++;
        if (result2 == 1) p1wins1++;
        if (result1 == 2) p2wins1++;
        if (result2 == 2) p2wins1++;

        int p1wins2 = 0, p2wins2 = 0;
        
        int result3 = func(a1, b2);
        int result4 = func(a2, b1);
        if (result3 == 1) p1wins2++;
        if (result4 == 1) p1wins2++;
        if (result3 == 2) p2wins2++;
        if (result4 == 2) p2wins2++;

        int winCount = 0;
        if (p1wins1 > p2wins1) winCount++;
        if (p1wins2 > p2wins2) winCount++;

        cout << winCount << endl;
    }

    return 0;
}
