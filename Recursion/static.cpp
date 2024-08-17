#include <iostream>
using namespace std;

int fun(int n){
	static int x=0;  //here the static variable memeory block will only be created only once in the code section
	if(n>0){
		x++;
		return fun(n-1) + x;
	}
	return 0;
}

int main(){
	int a=5;
	cout << fun(a) << " ";
}