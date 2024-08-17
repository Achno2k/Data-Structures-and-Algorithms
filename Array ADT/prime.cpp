#include<iostream>

using namespace std;

bool isPrime(int n){
	for(int i=2; i<=n/2; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}
int main(){
	if(isPrime(7))
		cout << "Prime" << endl;
	else
		cout << "Not Prime" << endl;

	return 0;
}