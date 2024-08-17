#include <bits/stdc++.h>
using namespace std;

int main(){
	pair<int, int> p = {1, 3};
	cout << p.first << " " << p.second << endl;
	// cout << p << endl;   can't do this, can only access it using a iterator

	pair<int, pair<int, int>> p1 = {1, {2, 3}};
	cout << p1.first << " " << p1.second.first << " "<< p1.second.second << endl;


	pair<int, int> arrOfPairs[] = { {1,2}, {2,3}, {3,4} };
	cout << arrOfPairs[0].first << " " << arrOfPairs[1].second << " " << arrOfPairs[2].first << endl;
	return 0;
}