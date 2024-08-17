#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;

	int left[n], right[n];
	for(int i=0; i<n; i++){
		cin >> left[i];
		cin >> right[i];
	}
	
	int time = 0;
	int leftOpen = 0;
	int rightOpen = 0;

	for(int i=0; i<n; i++){
		if(left[i] == 1)
			leftOpen ++;
		if(right[i] == 1)
			rightOpen ++;
	}

	if(leftOpen == 0 && rightOpen ==0){
		cout << 0 << endl;
		return;
	}

	else if(leftOpen < rightOpen){
		for(int i=0; i<n; i++){
			if(left[i] == 1){
				left[i] = 0;
				time++;
			}
			if(right[i] == 0){
				right[i] = 1;
				time++;
			}
		}
	}
	else{
		for(int i=0; i<n; i++){
			if(right[i] == 1){
				right[i] = 0;
				time++;
			}
			if(left[i] == 0){
				left[i] = 1;
				time++;
			}
		}
	}
	cout << time << endl;
}

int main()
{
	solve();
	return 0;	
}