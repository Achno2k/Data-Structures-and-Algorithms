#include <bits/stdc++.h>
using namespace std;

void solve(){
	string g;
	cin >> g;

	string h;
	cin >> h;

	string p;
	cin >> p;

	unordered_map<char, int> freq1;
	unordered_map<char, int> freq2;

	for(auto ch : g)
		freq1[ch] ++;
	for(auto ch : h)
		freq1[ch] ++;
	for(auto ch : p)
		freq2[ch] ++;

	if(freq1 == freq2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}

int main()
{
	solve();
	return 0;
}