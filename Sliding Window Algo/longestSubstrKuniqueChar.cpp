#include <bits/stdc++.h>
using namespace std;

int solve(string& s, int k) {
	int n = s.size();
	
	int maxLen = -1;
	int i = 0;
	int j = 0;
	unordered_map <char, int> mp;
	
	while (j < n) {
		mp[s[j]]++;
		if (mp.size() == k) {
			maxLen = max(maxLen, j-i+1);
		} 
		else {
			while (mp.size() > k) {
				mp[s[i]]--;
				if (mp[s[i]] == 0) {
					mp.erase(s[i]);
				}
				i++;
			}
		}
		j++;
	}
	return maxLen;
}

int main() {
	string s = "aabacbebebe";
	int k = 3;
	cout << "Longest Substring with unique characters: " <<solve(s, k) << endl;

	return  0;
}