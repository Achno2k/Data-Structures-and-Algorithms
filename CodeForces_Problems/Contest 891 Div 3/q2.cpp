#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve(){
	int t;
	cin >> t;

	while(t--){
		long long int x;
		cin >> x;

		vector<int> num;
		while(x > 0){
			num.push_back(x % 10);
			x /= 10;
		}

		string prev = "";
		for(auto i : num){
			prev += to_string(i);
		}

		reverse(prev.begin(), prev.end());
		long long int prevNum = stoll(prev);

		for(int k=1; k<num.size(); k++){
			if(num[k] == 9){
				for(int i=k+1; i<num.size(); i++){
					if(num[i] < 9){
						num[i]++;
						k = i;
					}
				}
			}
			if(num[k - 1] >= 5){
				num[k] ++;
			}

			for(int i=0; i<k; i++){
				num[i] = 0;
			}

			string curr = "";
			for(auto i : num)
				curr += to_string(i);

			reverse(curr.begin(), curr.end());
			long long int currNum = stoll(curr);
			if(prevNum > currNum){
				cout << prevNum << endl;
				break;
			}
			prevNum = currNum;
		}
	}
}

int main(){
	solve();
	return 0;
}