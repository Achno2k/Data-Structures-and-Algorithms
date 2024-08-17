#include <bits/stdc++.h>
using namespace std;

void solve(){
	string str;
	cin >> str;

	bool flag = true;
	int count = 1;
	int i = 1;

	for(int i = 1; i < str.length(); i++){
		if(str[i] == str[i-1]){
			count ++;
			if(count >= 7){
				flag = false;
				break;
			}
		}else{
			count = 1; 
		}
	}

	if(!flag)

		cout << "YES" << endl;
	else
		 cout << "NO" << endl;
}

int main()
{
	solve();
	return 0;
}