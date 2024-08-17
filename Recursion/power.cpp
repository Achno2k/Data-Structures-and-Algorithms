#include <iostream>
using namespace std;

int pow(int m, int n){
	if(n>0)
		return m*pow(m, n-1);
	return 1;
}

int main(){
	int a=2, n=5;
	cout <<  pow(2, 5) << endl;

	return 0;
}