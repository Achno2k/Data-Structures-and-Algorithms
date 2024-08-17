//Merge Intervals

#include <bits/stdc++.h>
using namespace std;
//Brute Force
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i=0; i<n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }
            for (int j=i+1; j<n; j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }

//Optimized
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i=0; i<n; i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }   

int main(){
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>> ans = merge(intervals);
	for (auto i : ans) {
		cout << i[0] << "," << i[1] << " ";
	}
	return 0;
}