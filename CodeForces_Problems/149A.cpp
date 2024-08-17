#include <bits/stdc++.h>
using namespace std;

void solve(){
	int k;
	cin >> k;

	vector<int> vec(12);
	for (int i = 0; i < 12; ++i){
		cin >> vec[i];
	}

	if(k == 0){
		cout << 0 << endl;
		return;
	}

	sort(vec.begin(), vec.end());

	int count = 0;
	int sum = 0;
	for(int i=11; i>=0; --i){
		sum += vec[i];
		count ++;
		if(sum >= k){
			break;
		}
	}
	
	if(sum < k)
		cout << -1 << endl;
	else
		cout << count << endl;
}

int main()
{
	solve();
	return 0;
}