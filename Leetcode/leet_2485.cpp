#include <bits/stdc++.h>
using namespace std;
int pivotInteger(int n) {
        int totalSum = (n * (n + 1)) / 2;
        int sumX = 0;
        for (int i = 1; i <= n; i++) {
            sumX += i;

            if (sumX == totalSum - sumX) {
                return i;
            }
        }
        cout << totalSum << ' ' << sumX << endl;
        return -1;
    }

int main(){
	cout << pivotInteger(8) << endl;
	return 0;
}