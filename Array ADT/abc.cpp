#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int missingElement(vector<int>& A, int n){
	unordered_map<int,int> freqMap;
	for(int i : A)
		freqMap[i]++;

	for(int i=1; i<=n+1; i++){
		if(freqMap.find(i) == freqMap.end())
			return i;
	}
	return -1;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5};
	int x = missingElement(A, 5);
	cout << "Missing Element : " << x ;

	return 0;
}