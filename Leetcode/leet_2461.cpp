#include <bits/stdc++.h>
using namespace std;

void maximumSubarraySum(vector<int>& nums, int k) {
        int current_sum = 0;
        int max_sum = INT_MIN;
        unordered_map <int, int> hashMap;
        int i = 0;
        while (i < k) {
            hashMap[nums[i]] ++;
            if (hashMap[nums[i]] != 1) {
                hashMap[nums[i]] --;
                current_sum = 0;
                k = k + i;
                current_sum = nums[i];
            } else {
                current_sum += nums[i];
            }
            i++;    
        }
        cout << current_sum << endl;
        max_sum = max_sum < current_sum ? current_sum : max_sum;
        cout << max_sum << endl;

        
        for (int i=k; i<n; i++) {
        	
        }


    }

int main(){
	vector<int> nums = {1,2,4,5};
	maximumSubarraySum(nums, 3);
	return 0;
}



