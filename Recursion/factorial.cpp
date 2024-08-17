#include <iostream>
using namespace std;

int fact(int n){
	if(n>0)
		return n*fact(n-1);
	return 1;
}

int main(){
	int n=5;
	cout << fact(n) << endl;
}