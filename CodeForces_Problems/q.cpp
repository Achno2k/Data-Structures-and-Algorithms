#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int conversations(vector<int>& h, int m, int k, int H) {
    unordered_map<int, int> hash;
    int count = 0;

    for (int i = 0; i < h.size(); ++i) {
        for (int j = 0; j < m; ++j) {
            int height_diff = h[i] - (j + 1) * k;
            if (height_diff == 0 || height_diff == H) {
                continue;
            }
            if (hash.find(height_diff) != hash.end()) {
                count += hash[height_diff];
            }
        }
        for (int j = 0; j < m; ++j) {
            int height_diff = h[i] - (j + 1) * k;
            hash[height_diff]++;
        }
    }

    return count;
}

int main() {
	int t;
	cin >> t;
	while(t > 0){
		int n, m, k, H;
		cin >> n >> m >> k >> H;
		vector<int> heights(n);
		for(int i=0; i<n; i++){
			cin >> heights[i];
		}
		int result = conversations(heights, m, k, H);
    	cout << result << endl;

    	t--;
	}
  
    return 0;
}
