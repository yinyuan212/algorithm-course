#include <iostream>
#include <vector>
using namespace std;

// Function to print array with comma separation
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ",";
    }
    cout << endl;
}

// Function to print partition results
void printPartition(const vector<int>& left, const vector<int>& right, int pivot) {
    cout << "pivot:" << pivot << endl;
    if (left.empty()) {
        cout << endl;
    } else {
        for (int i = 0; i < left.size(); i++) {
            cout << left[i];
            if (i < left.size() - 1) cout << " ";
        }
        cout << endl;
    }
    if (right.empty()) {
        cout << endl;
    } else {
        for (int i = 0; i < right.size(); i++) {
            cout << right[i];
            if (i < right.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

// Partition function using second element as pivot
int partition(vector<int>& arr, int low, int high) {
    if (low + 1 > high) return low;  // 確保至少有 2 個元素

    int pivot = arr[low + 1];  // 直接選擇第二個元素為 pivot

    vector<int> left, right;
    for (int i = low; i <= high; i++) {
        if (i == low + 1) continue;  // 略過 pivot 本身
        if (arr[i] < pivot) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }

    if (high - low + 1 >= 3) {
        printPartition(left, right, pivot);
    }

    // 重新組合陣列
    int i = low;
    for (int num : left) arr[i++] = num;
    int pivotPos = i;
    arr[i++] = pivot;
    for (int num : right) arr[i++] = num;

    return pivotPos;
}

// Quicksort implementation
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n - 1);
    
    cout << "result:";
    printArray(arr);
    
    return 0;
}