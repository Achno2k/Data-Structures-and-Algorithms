#include <bits/stdc++.h>
using namespace std;

string distinctChars(string str1, string str2){
	int hashtable[26]{0};
	string answer = "";
	for (char ch: str1) {
		hashtable[ch-'a'] = 1;
	}

	for (char ch: str2) {
		if (hashtable[ch-'a'] == 1 || hashtable[ch-'a'] == -1) {
			hashtable[ch-'a'] = -1;
		} else {
			hashtable[ch-'a'] = 2;
		}
	}

	for (int i=0; i<26; i++) {
		if (hashtable[i] == 1 || hashtable[i] == 2) {
			answer += static_cast<char>(i + 'a');
		}
	}
	return answer;
}

int main(){
	string answer = distinctChars("characters", "alphabets");
	cout << answer << endl;
	return 0;
}