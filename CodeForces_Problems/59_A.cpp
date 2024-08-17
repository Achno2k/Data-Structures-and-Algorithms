#include <bits/stdc++.h>
using namespace std;

void changeCases(string& s){
	int lower = 0;
	int upper = 0;
	for(char ch : s){
		if(ch >= 'a' && ch <= 'z')
			lower++;
		else
			upper++;
	}

	if(lower >= upper){
		for(char& ch : s){
			if(ch >= 'A' && ch <= 'Z'){
				ch = ch + 32;
			}
		}
	}
	else{
		for(char& ch : s){
			if(ch >= 'a' && ch <= 'z')
				ch = ch - 32;
		}
	}	
}


int main(){
	string s1 = "ViP";
	string s2 = "hOusE"  
	changeCases(s1);
	changeCases(s2);
	cout << s1 << endl;
	cout << s2 << endl;

	return 0;
}