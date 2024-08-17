#include <bits/stdc++.h>
using namespace std;

int countOccureneces (string str, char ch) {
	int count = 0;
	for (char s: str) {
		if (s == ch) {
			count ++;
		}
	}
	return count;
}

void garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int glassTruck = 0;
        int paperTruck = 0;
        int metalTruck = 0;
        
        int glassIdx = -1;
        int paperIdx = -1;
        int metalIdx = -1;

        int n = garbage.size();
        for (int i=0; i<n; i++)  {
            if (garbage[i].find('G') != string::npos) {
                glassIdx = max(glassIdx, i);
                glassTruck += countOccureneces(garbage[i], 'G');
            }
            if (garbage[i].find('P') != string::npos) {
                paperIdx = max(paperIdx, i);
                paperTruck += countOccureneces(garbage[i], 'P');
            }
            if (garbage[i].find('M') != string::npos) {
                metalIdx = max(metalIdx, i);
                metalTruck += countOccureneces(garbage[i], 'M');
            }
        }

        for (int i=0; i<glassIdx; i++){
            glassTruck += travel[i];
        }
        for (int i=0; i<paperIdx; i++){
            paperTruck += travel[i];
        }
        for (int i=0; i<metalIdx; i++){
            metalTruck += travel[i];
        }

        return glassTruck+paperTruck+metalTruck;
}


int main(){
	vector<string> garbage = {"G","P","GP","GG"};
	vector<int> travel = {2,4,3};

	garbageCollection(garbage, travel);

	return 0;
}