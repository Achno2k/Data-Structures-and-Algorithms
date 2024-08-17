#include <iostream>
using namespace std;

//using recursion
double e(int x, int n){
	static double p=1, f=1;
	double r;
	if(n==0)
		return 1;
	else{
		r=e(x,n-1);
		p=p*x;
		f=f*n;
		return r+ p/f;
	}
}
//using horner's rule 
double e1(int x, int n){
	static double r=1;
	if(n==0)
		return r;
	else{
		r=1+(x*r/n); //here make sure to multiply x*r first then divde it by n as it gives an "int" value if done later
		return e1(x,n-1);
	}

}
int main(){
	cout << "The expansion of e is using recursion: " << e(1,10) << endl;
	cout << "The expansion of e is using horner's rule: " << e1(1,10) << endl;
	return 0;
}