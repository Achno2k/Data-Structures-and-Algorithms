#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v; //this creates an empty container

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.emplace_back(4);	//this works the same as push_back() but is generally faster

	vector<pair<int, int>> vecPair;
	vecPair.push_back({1,2});	//this needs a pair to be pushed back explicitely
	vecPair.emplace_back(1,2);	//this automatically assumes that the two numbers are a pair

	vector<int> vec(5, 100); //{100, 100, 100, 100, 100}

	vector<int> vec1(vec); //also {100, 100, 100, 100, 100}

	//ITERATORS
	vector<int>::iterator it = v.begin();
	// cout << &it << endl; 	//0xee1ffffb08   
	// cout << *it << endl;
	// cout << *++it << endl;
	// cout << *it+2 << endl;


	// vector<int>::iterator it = v.end();		//{1,2,3} --> here it points right after 3, but not at 3.

	cout <<  v[0] << " = " << v.at(0) << endl;
	cout << v.back() << endl;	//gives the last element in the vector

	for (auto it=v.begin(); it!=v.end(); it++){
		cout << *it <<  " ";
	}
	cout << endl;

	cout << "Hello world" << endl;

	return 0;
}