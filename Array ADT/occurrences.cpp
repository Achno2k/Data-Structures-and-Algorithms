#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

bool unique_occur(int arr[], int size) {
    int freq[MAX_SIZE] = {0};
    int occurrCount[MAX_SIZE] = {0};

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

   for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            cout << "Element " << i << " occurs " << freq[i] << " times." << endl;
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            occurrCount[freq[i]]++;
            if (occurrCount[freq[i]] > 1) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int arr[] = {1,2,3,4,4,5,5,6,7,7,7};
    int size = sizeof(arr) / sizeof(arr[0]);


    if (unique_occur(arr, size)) {
        cout << "\nElements with same occurrences are present" << endl;
    } else {
        cout << "No elements have the same occurrences" << endl;
    }

    return 0;
}
