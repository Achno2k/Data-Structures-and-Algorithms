#include <bits/stdc++.h>
using namespace std;

void leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSum (n);
        vector<int> rightSum (n);
        vector<int> answer (n);
        
        int sumLeft = 0;
        int sumRight = 0;

        for (int i=0; i<n; i++) {
            leftSum[i] += sumLeft;
            sumLeft += nums[i];
            
            rightSum[n-i-1] += sumRight;
            sumRight += nums[n-i-1];
        }

        for (int i=0; i<n; i++) {
            answer[i] = abs(leftSum[i]-rightSum[i]);
        }

        // return answer;

        for (auto i: answer) {
        	cout << i << ' ';
        }
    }

int main(){
	vector<int> nums = {10, 4, 8, 3};
	leftRightDifference(nums);
	
	return 0;
}