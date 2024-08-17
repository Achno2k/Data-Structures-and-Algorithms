#include <bits/stdc++.h>
using namespace std;

void productExceptSelf(vector<int>& nums) {
    
    vector<int> answer (nums.size());
    for (int i=1; i<nums.size(); i++) {
        nums[i] = nums[i] * nums[i-1];
    }
        
    for (int i: nums) {
    	cout << i << " ";
    }
}

int main(){
	vector<int> nums = {1, 2, 3, 0, 4};
	productExceptSelf(nums);
	return 0;
}