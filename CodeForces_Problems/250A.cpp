#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
    cin >> n;
    
    int min_time = INT_MAX;
    int min_count = 0;
    int town_index = -1;

    for(int i=0; i<n; i++){
    	int element;
    	cin >> element;

    	if(element < min_time){
    		min_time = element;
    		min_count = 1;
    		town_index = i + 1;
    	}
    	else if(element == min_time){
    		min_count ++;
    	}
    }
    if(min_count == 1){
    	cout << town_index << endl;
    }
    else
    	cout << "Still Rozdil" << endl;
}

int main()
{
	solve();
	return 0;
}
