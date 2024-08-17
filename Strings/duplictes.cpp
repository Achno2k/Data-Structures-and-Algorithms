#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void duplicates(string str)
{
	int *h=new int[26]{0};
	int i=0;
	while(str[i]!='\0'){
		h[str[i]-97]++;
		i++;
	}
	cout << "Duplicated characters :" << endl;
	for(i=0; i<26; i++){
		if(h[i]>1){
			cout << static_cast<char>(i+97) << " -> " << h[i] <<  " times" << endl;
		}
	}
	delete[] h;
}

int main()
{
	string s = "aman";
	duplicates(s);

	return 0;
}