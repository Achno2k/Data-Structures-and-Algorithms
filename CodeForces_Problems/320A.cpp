#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n;
	cin >> n;

	string num = to_string(n);
	int i = 0;
	bool flag = true;

	while(i < num.length()){
		if(i + 2 < num.length() && num.substr(i, 3) == "144"){
			i += 3;
		}
		else if(i + 1 < num.length() && num.substr(i, 2) == "14"){
			i += 2;
		}
		else if(num[i] == '1'){
			i++;
		}
		else{
			flag = false;
			break;	
		}
	}

	if(flag)
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	solve();
	return 0;
}