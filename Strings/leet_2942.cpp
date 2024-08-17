#include <bits/stdc++.h>
using namespace std;

vector<int> func(vector<string>& words, char x) {
	vector<int> ans;
    int index = 0;
    for(const string& str: words) {
        if (str.find(x) != string::npos) {
            ans.push_back(index);
            cout << index;
        }
        index++;
    }
    return ans;
}

int main(){
	vector<string> words = {"leet", "code"};
	vector<int> ans = func(words, 'e');

	cout << endl;
	for (int i: ans) {
		cout << i <<  " ";
	}

	return 0;
}