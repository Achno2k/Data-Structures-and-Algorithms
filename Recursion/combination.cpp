#include <iostream>
using namespace std;

//using formula
int fact(int n)
{
	if(n==0) return 1;
	else{
		return n*fact(n-1);
	}
}
int combination(int n, int r){
	int num = fact(n);
	int den = fact(r) * fact(n-r);

	return num/den;
}

//using recursion
int rcomb(int n, int r){
	if(n==r||r==0)
		return 1;
	else{
		return rcomb(n-1, r-1)+rcomb(n-1,r);
	}
}

int main()
{
	int n, r;
	cin >> n >> r;
	cout << "Using normal formula for combination: " <<combination(n,r) << endl;
	cout << "Using the concept of pascal's triangle: " << rcomb(n,r) << endl;
	return 0;
}