#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s = "welcome";
	int i,j;

	//stirng cases changed
	for(i=0; i<s.length(); i++){
		if(s[i]>='a' && s[i]<='z')
			s[i] = s[i]-32;
		else
			s[i] = s[i]+32;
	}
	cout << s << endl;

	//string reveresed
	for(i=0,j=s.length()-1;i<j; i++,j--){
		swap(s[i],s[j]);
	}
	cout << s << endl;
	
	//comparing strings
	string a = "Gunnu is crazy";
	string b = "Gunnu is mad";
	if(a==b)
		cout << "Equal" << endl;
	else
		cout << "Not Equal" << endl;

	return 0;
}