#include <bits/stdc++.h>
using namespace std;

void solve(){
	int t;	
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		if(n == 0 || n == 1){
			cout << "NO" << endl;
		}
		else{
			int arr[n];
			for(int i=0; i<n; i++){
				cin >> arr[i];
		}

			int even = 0;
			int odd = 0;

			for(int i=0; i<n; i++){
				if(arr[i] % 2 == 0)
					even ++;
				else
					odd++;
			}

			if(odd % 2 == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}	
	}
}

int main() 
{
	solve();
	return 0;
}