#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int>& vec1, vector<int>& vec2){
	vector<int>v;
	int i{0}, j{0};
	while(i < vec1.size() && j < vec2.size()){

		if(vec1[i] < vec2[j])
			v.push_back(vec1[i++]);	
		else
			v.push_back(vec2[j++]);
	} 

	while(i < vec1.size())
		v.push_back(vec1[i++]);

	while(j < vec2.size())
		v.push_back(vec2[j++]);	
	
	return v;
}

void mergeSingle(vector<int>& vec3, int mid, int low, int high){
	vector<int> vtr;
	int i{low}, j{mid+1};
	while(i<=mid && j<=high){
		if(vec3[i] < vec3[j])
			vtr.push_back(vec3[i++]);
		else
			vtr.push_back(vec3[j++]);
	}
	while(i <= mid)
		vtr.push_back(vec3[i++]);
	while(j <= high)
		vtr.push_back(vec3[j++]);

	vec3.clear();
	for(auto i : vtr)
		vec3.push_back(i);
}

int main()
{
	//Merging two lists (arrays)
	vector<int> vec1 = {2, 4, 6, 8, 10};
	vector<int> vec2 = {1, 3, 5, 7, 9};
	vector<int> vec = Merge(vec1, vec2);

	cout << "Merged List: ";
	for(auto i : vec)
		cout << i << " ";

	cout << endl;

	//Merging a single list
	vector<int> vec3 = {3, 5, 7, 9, 2, 4, 6, 8};
	mergeSingle(vec3, 3, 0, vec3.size()-1);

	cout << "Single Merged List: ";
	for(auto i : vec3)
		cout << i << " ";

	return 0;
}