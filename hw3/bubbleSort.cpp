#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int L;
        cin >> L;
        vector<int> arr(L);
        
        for (int i = 0; i < L; i++) cin >> arr[i];

        int swaps = bubbleSort(arr);
        cout << "Optimal swapping takes " << swaps << " swaps." << endl;
    }

    return 0;
}
