#include <bits/stdc++.h>
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> results;
        int n = nums.size();

        for (int i = 0; i <= n - k; ++i) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            vector<int> temp = subarray;
            sort(temp.begin(), temp.end());

            if (temp != subarray) {
                results.push_back(-1);
                continue;
            }

            bool isConsecutive = true;
            for (int j = 1; j < k; ++j) {
                if (subarray[j] != subarray[j - 1] + 1) {
                    isConsecutive = false;
                    break;
                }
            }
            if (isConsecutive) {
                results.push_back(subarray.back());
            } else {
                results.push_back(-1);
            }
        }

        return results;
}

int main () {
	vector<int> nums = {3,2,3,2,3,2};
	vector<int> res = resultsArray(nums, 2);

	for (auto it: res) {
		cout << it << " ";
	} 

	return 0;
}