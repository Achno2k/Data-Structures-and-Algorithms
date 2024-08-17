#include <iostream>
using namespace std;

int arr[10] = {-1};
//using recursion
int rfib(int n){
	if(n<=1)
		return n;
	else
		return rfib(n-2)+ rfib(n-1);
}


//using memoizaton
int mfib(int n)
{
	if(n<=1){
		arr[n]=n;
		return n;
	}else{
		if(arr[n-1]==-1){
			arr[n-1]=mfib(n-1);
		}else{
			arr[n-2]=mfib(n-2);
		}
		return mfib(n-1)+mfib(n-2);
	}
}


int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cout << rfib(i) << " ";
	}
	cout << endl;
	for(int i=0; i<n; i++){
		cout << mfib(i) << " ";
	}
}