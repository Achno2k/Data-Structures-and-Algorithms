#include <iostream>
using namespace std;

//using recursion --> Time : O(n) & Space : O(n)
/*int sum(int n){
	if(n>0)
		return n+sum(n-1);
	return 0;
}*/

int main()
{
	int n=5;
	cout << n*((n+1)/2) << endl; //using formula

	return 0;
}