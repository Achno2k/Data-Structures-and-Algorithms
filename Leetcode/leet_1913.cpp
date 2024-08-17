#include <bits/stdc++.h>
using namespace std;

int maxProductDifference(vector<int>& nums) {
        long long int answer; 
        long long int max1 = INT32_MIN;
        long long int max2 = INT32_MIN;
        long long int min1 = INT32_MAX;
        long long int min2 = INT32_MAX;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        
        // if (max2 == INT32_MIN || min2 == INT32_MAX) {
        //     return 0;
        // }

        answer = (max1*max2) - (min1*min2);
        return answer;
    }

int main(){
    vector<int> nums = {10,10,10,10};
    cout << maxProductDifference(nums);
    return 0;
}
