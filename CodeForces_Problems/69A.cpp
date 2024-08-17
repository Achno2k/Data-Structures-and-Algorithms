#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin >> n;

	int x_coor, y_coor, z_coor;

	for(int i=0; i<n; i++){
		int x, y, z;
		cin >> x >> y >> z;

		x_coor += x;
		y_coor += y;
		z_coor += z;
	}
	
	if(x_coor == 0 && y_coor == 0 && z_coor == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}

int main()
{
	solve();
	return 0;
}